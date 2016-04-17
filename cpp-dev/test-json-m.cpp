
#include <json-c/json.h>
#include <stdio.h>
#include <string>

int main() {
    printf("xxx\n");
    
    {
    std::string json = "{\"op\":\"set\"\"metak\":\"foo\"}";
    printf("json = %s\n", json.c_str());
    json_object *root = json_tokener_parse(json.c_str());
    if (!root) {
        printf("root = NULL\n");
    }
    printf("root = %x\n", root); 
   
    }

    {
    std::string json = "{\"op\":\"set\",}";
    printf("json = %s\n", json.c_str());
    json_object *root = json_tokener_parse(json.c_str());
    if (!root) {
        printf("root = NULL\n");
    }
    printf("root = %x\n", root); 
   
    }
   
    {
    std::string json = "{\"op:\"set\",}";
    printf("json = %s\n", json.c_str());
    json_object *root = json_tokener_parse(json.c_str());
    if (!root) {
        printf("root = NULL\n");
    }
    printf("root = %x\n", root); 
   
    }
    return 0;
}
