#include <stdio.h>
#include <string>

#include <arpa/inet.h>
#include <rpc/xdr.h>
#include <rpc/rpc_msg.h>

int main(int argc, char* argv[]) {

    std::string buffer;

    struct rpc_msg reply;
    memset((void*)&reply, 0, sizeof(reply));
    reply.rm_xid =  0x123456;
    reply.rm_direction = REPLY;

    reply.rm_reply.rp_stat = MSG_DENIED;
    reply.rjcted_rply.rj_stat = RPC_MISMATCH;
    reply.rjcted_rply.rj_vers.low = 2;
    reply.rjcted_rply.rj_vers.high = 2;

    size_t header_xdr_size = xdr_sizeof((xdrproc_t)xdr_replymsg, &reply);
    XDR xdr;
    buffer.reserve(header_xdr_size);
    printf("before xdr|buffer_size:%d|buffer_capacity:%d\n", buffer.length(), buffer.capacity());
    xdrmem_create(&xdr, (char*)buffer.c_str(), header_xdr_size, XDR_ENCODE);
    xdr_replymsg(&xdr, &reply);
    //不会引起size的变化
    printf("header_xdr_size:%d|head_reserve_size:%d\n", header_xdr_size, buffer.size());
    printf("after xdr|buffer_size:%d|buffer_capacity:%d\n", buffer.length(), buffer.capacity());

    for (int i = 0; i < header_xdr_size; i++) {
        printf("buffer:%x\n", buffer.c_str()[i]);
    }
    
    return 0;
}
