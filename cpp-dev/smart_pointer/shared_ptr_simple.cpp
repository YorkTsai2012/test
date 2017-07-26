//g++ -g shared_ptr_simple.cpp -std=c++0x

#include <stdio.h>

#include <string>
#include <memory>
#include <map>

void TestArray() {
    std::shared_ptr<unsigned long> array_ptr; 
    array_ptr.reset();
    array_ptr = std::shared_ptr<unsigned long>(new unsigned long[2]);
    array_ptr.get()[0] = 0;
    array_ptr.get()[1] = 1;

    for (int i = 0; i < 2 ; i++) {
        printf("%lu\n", array_ptr.get()[i]);
    }
}

class Req {

public:

    std::string session;
    unsigned machine_id;

    void DebugString() { 
        printf("addr:%x|session:%s|machine_id:%u\n", this, session.c_str(), machine_id);
    }

};
typedef std::shared_ptr<Req> ReqPtr;

void CallAlloc(ReqPtr c) {

    c->DebugString();
    printf("c shares:%d\n", c.use_count());

    std::map<std::string, ReqPtr> pool;
    //make_pair 涉及都 shared_ptr时 没有拷贝操作
    //pool.insert(std::make_pair<std::string, ReqPtr>(c->session, c));
    pool[c->session] = c;

    pool[c->session]->DebugString();
    printf("d shares:%d\n", pool[c->session].use_count());

}

void TestAlloc() {

    ReqPtr a(new Req);
    a->machine_id = 100;
    a->session = "abc";

    ReqPtr b;
    //shared_ptr  如果 reset 一个 裸指针  ，不会产生计数
    b.reset(a.get());

    b->DebugString();

    printf("a shares:%d\n", a.use_count());
    printf("b shares:%d\n", b.use_count());

    CallAlloc(a);

    printf("a shares:%d\n", a.use_count());
    a.reset();
    printf("b shares:%d\n", b.use_count());
}

class InternalMsgReq {

public:
    std::string queue_id;
    std::string session;

    void DebugString() {
        printf("queue_id:%s|session:%s\n", queue_id.c_str(), session.c_str());
    }
};
typedef std::shared_ptr<InternalMsgReq> InternalMsgReqPtr;

void TestString() {

    //InternalMsgReqPtr msg_req;
    InternalMsgReq* msg_req = new InternalMsgReq;
    msg_req->queue_id = "abc";
    msg_req->session = "123";

    msg_req->DebugString();

    InternalMsgReqPtr sp;
    sp.reset(msg_req);

    sp->DebugString();
}

void TestNull() {

    InternalMsgReq* p = new InternalMsgReq;
    InternalMsgReqPtr a(p);
    InternalMsgReqPtr b(p);

}

int main(int argc, char* argv[]) {

    //TestAlloc();
    //TestString();
    TestNull();

    return 0;
}
