#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statfs.h>
#include <errno.h>

void PrintFsInfo(struct statfs* fsinfo) {

    printf("type:%ld\n", fsinfo->f_type);
    printf("bsize:%ld\n", fsinfo->f_bsize);
    printf("blocks:%ld\n", fsinfo->f_blocks);
    printf("bfree:%ld\n", fsinfo->f_bfree);
    printf("bavail:%ld\n", fsinfo->f_bavail);
    printf("files:%ld\n", fsinfo->f_files);
    printf("ffree:%ld\n", fsinfo->f_ffree);
    printf("fsid:%lu\n", fsinfo->f_fsid);
    printf("namelen:%ld\n", fsinfo->f_namelen);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "path");
        exit(10);
    }

    char *path = argv[1];
    struct statfs fsinfo;
    int ret = statfs(path, &fsinfo);
    if (ret) {
        printf("statfs fail|err:%s|errno:%d", strerror(errno), errno);
        exit(10);
    }

    PrintFsInfo(&fsinfo);
    return 0;
}
