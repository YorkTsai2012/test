
/*
 * g++ uuid_test.cpp -luuid
*/

#include <stdio.h>
#include <uuid/uuid.h>

int main() {

    uuid_t uu;  
    uuid_generate(uu);   
  
    int i;  
    for (i = 0; i < sizeof(uuid_t); i++) {   
        printf("%02x ", uu[i]);   
    }
    printf("\n");   

    char uuid_str[64];
    uuid_unparse(uu, uuid_str);
    printf("uuid_str:%s\n", uuid_str); 
  
    return 0;

}
