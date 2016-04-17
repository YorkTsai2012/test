//g++ test-mongo-delete.cpp -I/usr/include/libbson-1.0  -I/usr/include/libmongoc-1.0  -lbson-1.0 -lmongoc-1.0 -ljson-c 
#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:27017/");
    collection = mongoc_client_get_collection (client, "test", "test");

/*
    doc = bson_new ();
    bson_oid_init (&oid, NULL);
    BSON_APPEND_OID (doc, "_id", &oid);
    BSON_APPEND_UTF8 (doc, "hello", "world");

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
        printf ("Insert failed: %s\n", error.message);
    }

    bson_destroy (doc);
*/
    doc = bson_new ();
    //BSON_APPEND_OID (doc, "_id", &oid);
    BSON_APPEND_UTF8 (doc, "hello", "world");
    //MONGOC_REMOVE_NONE MONGOC_REMOVE_SINGLE_REMOVE
    if (!mongoc_collection_remove (collection, MONGOC_REMOVE_NONE, doc, NULL, &error)) {
        printf ("Delete failed: %s\n", error.message);
    } else {
        printf ("return 0, but the record don't exists\n");
    }

    bson_destroy (doc);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return 0;
}
