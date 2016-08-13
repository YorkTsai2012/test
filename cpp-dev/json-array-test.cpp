
/*
g++  -g  json-array-test.cpp    -I/use/local/include/json-c   -ljson-c
*/

#include <json-c/json.h>
#include <stdio.h>
#include <string>

typedef enum {
    ACTION_INVALID = -1,
    ACTION_ON,
    ACTION_KEEP,
    ACTION_OFF,
} CONFIG_ACTION_t;

std::string m_action = "";
uint64_t m_mtime = 0;

CONFIG_ACTION_t ParseConfig(const std::string& json) {
    json_object *root = json_tokener_parse(json.c_str());
    if (NULL == root) {
        return ACTION_INVALID;
    }
    //解析action
    json_object* node_action = NULL;
    if (json_object_object_get_ex(root, "action", &node_action)) {
        m_action = json_object_get_string(node_action);
        if ("off" == m_action) {
            json_object_put(root);
            return ACTION_OFF;
        } else if("on" != m_action) {
            json_object_put(root);
            return ACTION_INVALID;
        }
    } else {
        json_object_put(root);
        return ACTION_INVALID;
    }

    //解析mtime
    json_object* node_mtime = NULL;
    if (json_object_object_get_ex(root, "mtime", &node_mtime)) {
        uint64_t mtime = json_object_get_int64(node_mtime);
        printf("mtime:%lu\n", mtime);
        if (mtime == m_mtime) {
            json_object_put(root);
            return ACTION_KEEP;
        } else if ("off" == m_action) {
            m_mtime = mtime;
            json_object_put(root);
            return ACTION_OFF;
        } else if ("on" == m_action) {
            m_mtime = mtime;
        }
    } else {
        json_object_put(root);
        return ACTION_INVALID;
    }

    //解析list
    json_object* node_list = NULL;
    if (json_object_object_get_ex(root, "list", &node_list)) {
        int len = json_object_array_length(node_list);
        printf("array len:%d\n", len);
        if (0 == len) {
            //黑名单列表为空, 同样认为是停止操作
            json_object_put(root);
            return ACTION_OFF;
        }
        for(int i = 0; i < len; i++) {
            json_object *item = json_object_array_get_idx(node_list, i);
            if (NULL == item) {
                json_object_put(root);
                return ACTION_INVALID;
            }
            json_object* n_bucket = NULL;
            std::string bucket;
            if (json_object_object_get_ex(item, "bucket", &n_bucket)) {
                bucket = json_object_get_string(n_bucket);
            } else {
                json_object_put(root);
                return ACTION_INVALID;
            }
            json_object* n_speed = NULL;
            double speed = -1.0;
            if (json_object_object_get_ex(item, "speed", &n_speed)) {
                speed = json_object_get_double(n_speed);
            } else {
                json_object_put(root);
                return ACTION_INVALID;
            }
            //对配置数据的要求
            if ("" == bucket || speed <= 0.0) {
                json_object_put(root);
                return ACTION_INVALID;
            }
            printf("config from zk|bucket:%s|speed:%0.2f\n", bucket.c_str(), speed);
        }
    } else {
        printf("parse list error\n");
        json_object_put(root);
        return ACTION_INVALID;
    }
    //如果解析到列表完成，就说明是开启黑名单的操作
    json_object_put(root);
    return ACTION_ON;

}

int parse(const std::string& json) {
    json_object *root = json_tokener_parse(json.c_str());
    if (NULL == root) {
        printf("parse json string error\n");
        return -1;
    }
    int len = json_object_array_length(root);
    for(int i = 0; i < len; i++) {
        json_object *obj = json_object_array_get_idx(root, i);
        if (NULL == obj) {
            json_object_put(root);
            return -1;
        }
        json_object *node1 = NULL;
        if (json_object_object_get_ex(obj, "bucket", &node1)) {
            std::string bucket = json_object_get_string(node1);
            printf("bucket:%s\n", bucket.c_str());
        } else {
            json_object_put(root);
            return -1;
        }
        json_object *node2 = NULL;
        if (json_object_object_get_ex(obj, "speed", &node2)) {
            double speed = json_object_get_double(node2);
            printf("speed:%f\n", speed);
        } else {
            json_object_put(root);
            return -1;
        }
    }
    json_object_put(root);
    return 0;
}

int main() {

    const char* json = 
    "{"
    "\"action\":\"on\","
    "\"mtime\":1460987137,"
    "\"list\":[{\"bucket\":\"split\",\"speed\":0.5},{\"bucket\":\"foo\",\"speed\":2.6}]"
    "}";
    //const char* json = "{\"bucket\":\"split\",\"speed\":0.5}";
    //const char* json = "";
    printf("json:%s\n", json);
    CONFIG_ACTION_t ret = ParseConfig(json);
    printf("ret:%d\n", ret);

    return 0;
}
