#include <json-c/json.h>
#include <stdio.h>
#include <string>

int main() {
    std::string json = "{\"op\":\"set\"}";
    printf("an invalid json string = %s\n", json.c_str());
    json_object *root = json_tokener_parse(json.c_str());
    if (root) {
        printf("root = %x, is not NULL\n", root); 
    }
    return 0;
}
