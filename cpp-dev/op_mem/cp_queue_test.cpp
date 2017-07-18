#include <stdio.h>

#include <string>
#include <map>
#include <queue>

class Call {

public:
    std::string session;
};

class Task {

public:
    bool locked;
    std::queue<Call*> calls;
};
typedef std::map<std::string, Task> BigQueue;

void DumpTask(Task& task) {

    while (!task.calls.empty()) {
        printf("session:%s\n", task.calls.front()->session.c_str());
        task.calls.pop();
    }
}

void Test_block_rw_Q() {

    BigQueue Q;

    std::string qid = "abc";
    Q[qid].locked = true;
    Call* c1 = new Call;
    c1->session = "c1";
    Call* c2 = new Call;
    c2->session = "c2";
    Q[qid].calls.push(c1);
    Q[qid].calls.push(c2);

    Task t = Q[qid];    
    DumpTask(t);
    DumpTask(Q[qid]);

}

int main(int argc, char* argv[]) {

    Test_block_rw_Q();

    return 0;
}
