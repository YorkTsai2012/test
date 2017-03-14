/*
 * 哈希函数对比 http://mp.weixin.qq.com/s/IzOtTEflyCb8MIlea8ptrQ
 * g++ farmhash_test.cpp -luuid -lfarmhash -o farmhash_test
 */

#include <farmhash.h>
#include <uuid/uuid.h>
#include <stdio.h>
#include <set>

uint64_t GenerateUuid64() {
    uuid_t uu;
    char out[37];
    uuid_generate(uu);
    uuid_unparse_lower(uu, out);
    return util::Hash64(out, 37);
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("usage: %s %s\n", argv[0], "scale");
        exit(1);
    }

    time_t start = time(NULL);
    std::set<uint64_t> pool;
    int cap = atol(argv[1]);
    for(int i = 0; i < cap; i++) {
        pool.insert(GenerateUuid64());
    }
    time_t end = time(NULL);
    printf("start: %d|end: %d|elapse: %d\n", start, end, end - start);
    printf("capacity: %d|pool size=%d\n", cap, pool.size());
    return 0;
}
