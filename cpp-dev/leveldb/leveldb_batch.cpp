/* make
 * g++ -g leveldb_demo.cpp -I/root/leveldb/include -L/root/leveldb/out-shared -lleveldb
 * ref
 * https://rawgit.com/google/leveldb/master/doc/index.html
 */

#include <cassert>
#include "leveldb/db.h"
#include "leveldb/write_batch.h"

int main(int argc, char* argv[]) {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    //options.error_if_exists = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    //assert(status.ok());
    printf("Open|status: %s\n", status.ToString().c_str());

    //basice operation: Put, Get and Delete
    std::string value = "value1";
    std::string key1 = "key1";
    std::string key2 = "key2";
    leveldb::Status s = db->Put(leveldb::WriteOptions(), key1, value);
    if (s.ok()) {
        printf("Put |key: %s|value: %s|status: %s\n", key1.c_str(), value.c_str(), status.ToString().c_str());
    }
    s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) {
        printf("Get |key: %s|value: %s|status: %s\n", key1.c_str(), value.c_str(), status.ToString().c_str());
    }
    s = db->Put(leveldb::WriteOptions(), key2, value);
    if (s.ok()) {
        printf("Put |key: %s|value: %s|status: %s\n", key2.c_str(), value.c_str(), status.ToString().c_str());
    }
    s = db->Delete(leveldb::WriteOptions(), key2);
    if (s.ok()) {
        printf("Delete |key: %s|value: %s|status: %s\n", key1.c_str(), value.c_str(), status.ToString().c_str());
    } else {
        printf("Delete Error|key: %s|value: %s|status: %s\n", key1.c_str(), value.c_str(), status.ToString().c_str());
    }

    //批量操作
    s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) {
        leveldb::WriteBatch batch;
        batch.Delete(key1);
        batch.Put(key2, value);
        leveldb::WriteOptions wops;
        wops.sync = true;
        s = db->Write(wops, &batch);
        if (s.ok()) {
            printf("Batch Delete(key1) Put(key2,value)|key1: %s|key2: %s|value: %s|status: %s\n",
                key1.c_str(), key2.c_str(), value.c_str(), status.ToString().c_str());
        }
    }

    //遍历
    leveldb::ReadOptions readOptions;
    readOptions.snapshot = db->GetSnapshot();
    leveldb::Iterator* it = db->NewIterator(readOptions);
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        printf("Iterate|key:%s|value:%s|status:%s\n",
            it->key().ToString().c_str(), it->value().ToString().c_str(), it->status().ToString().c_str());
    }
    delete it;
    db->ReleaseSnapshot(readOptions.snapshot);

    delete db;
}
