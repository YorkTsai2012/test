//g++ test-mongo-find.cpp -I/usr/include/libbson-1.0  -I/usr/include/libmongoc-1.0  -lbson-1.0 -lmongoc-1.0 -ljson-c
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
    const bson_t *doc;
    bson_t *query;
    char *str;

    mongoc_init ();

    //client = mongoc_client_new ("mongodb://192.168.8.42:27017");
    client = mongoc_client_new ("mongodb://172.16.1.13:27017");
    collection = mongoc_client_get_collection (client, "fileidx_db", "fileidx_col");
    query = bson_new ();
    //BSON_APPEND_UTF8 (query, "bucket", "peter-test");
    BSON_APPEND_UTF8 (query, "bucket", "preview");

    
    //MONGOC_QUERY_NONE
    cursor = mongoc_collection_find (collection, MONGOC_QUERY_SLAVE_OK, 0, 1, 0, query, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);
        printf ("%s\n", str);
        bson_free (str);
    }

    bson_destroy (query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}
