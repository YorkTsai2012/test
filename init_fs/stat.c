#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

void PrintStat(struct stat* info) {

    printf("dev_t:%lu\n", info->st_dev);  /* ID of device containing file */
    printf("ino_t:%lu\n", info->st_ino);     /* inode number */
    printf("mode_t:%lu\n", info->st_mode);    /* protection */
    printf("nlink_t:%lu\n", info->st_nlink);   /* number of hard links */
    printf("uid_t:%lu\n", info->st_uid);     /* user ID of owner */
    printf("gid_t:%lu\n", info->st_gid);     /* group ID of owner */
    printf("rdev_t:%lu\n", info->st_rdev);    /* device ID (if special file) */
    printf("off_t:%lu\n", info->st_size);    /* total size, in bytes */
    printf("blksize_t:%lu\n", info->st_blksize); /* blocksize for file system I/O */
    printf("blkcnt_t:%lu\n", info->st_blocks);  /* number of 512B blocks allocated */
    printf("st_atime:%lu\n",  info->st_atime) ;   /* time of last access */
    printf("st_mtime:%lu\n", info->st_mtime);   /* time of last modification */
    printf("st_ctime:%lu\n", info->st_ctime);   /* time of last status change */
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "path");
        exit(10);
    }

    char *path = argv[1];
    struct stat info;
    int ret = stat(path, &info);
    if (ret) {
        printf("stat fail|err:%s|errno:%d", strerror(errno), errno);
        exit(10);
    }

    PrintStat(&info);
    return 0;
}
