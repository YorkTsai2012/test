
/*

linux下的snprintf截断后会添加'\0'

*/

#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[]) {

	uint32_t m_current_topid = 30;
	char topid[2];
	int ret = snprintf(topid, sizeof(topid), "%u", m_current_topid);
	printf("ret:%d|topid:%s\n", ret, topid);

    for (int i = 0 ; i < sizeof(topid)/sizeof(topid[0]); i++) {
        printf("topid[%d]=%d\n", i, topid[i]);
    }

	return 0;
}
