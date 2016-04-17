
#include <json-c/json.h>
#include <stdio.h>
#include <string>

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

    const char* json = "[\n{\"bucket\":\"split\",\"speed\":0.5},{\"bucket\":\"foo\",\"speed\":2.6}\n]\n";
    //const char* json = "{\"bucket\":\"split\",\"speed\":0.5}";
    printf("json:%s\n", json);
    parse(json);


    return 0;
}
