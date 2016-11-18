/*
@compile: gcc -g -std=c99 linkedlist.c -o linked
@OJ: https://leetcode.com/problems/merge-two-sorted-lists/
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _Node;
typedef struct _Node Node;

struct _Node {
    int val;
    struct _Node* next;
};


Node* merge(Node* pa, Node* pb) {
    if (!pa && !pb) return NULL;
    else if(pa && !pb) return pa;
    else if(!pa && pb) return pb;

    Node* head = NULL;
    //当前比较的两个节点
    Node* t1 = NULL;
    Node* t2 = NULL;
    //确定头部
    if (pa->val < pb->val) {
        head = pa;
        t1 = pa->next;
        t2 = pb;
    } else {
        head = pb;
        t1 = pa;
        t2 = pb->next;
    }   
    Node* t = head; //记录前继节点
    while (t1 || t2) {
        if (t1 && t2) {
            if (t1->val < t2->val) {    
                t->next = t1;
                t1 = t1->next;
                t = t->next;
            } else {
                t->next = t2;
                t2 = t2->next;
                t = t->next;
            }
        } else if (t1) {
            t->next = t1;
            break;
        } else {
            t->next = t2;
            break;
        }
    }
    return head;
}


int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

Node* sorted_linked_list(int size) {
    srand((unsigned)time(NULL));
    int* arr = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50;
        printf("arr[%d]=%d ", i, arr[i]);
    }
    printf("\n");
    qsort(arr, size, sizeof(int), cmp);
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=%d ", i, arr[i]);
    }
    printf("\n");
    Node* head = NULL;
    Node* t = NULL;
    for (int i = 0; i < size; i++) {
        Node* tmp = malloc(sizeof(Node));
        //check success
        tmp->val = arr[i];
        tmp->next = NULL;
        if (!head) {
            head = tmp;
            t = head;
            continue;
        }
        t->next = tmp;
        t = t->next;
    }
    free(arr);
    return head;
}

void print_linked_list(Node* head) {
    Node* t = head;
    printf("linked_list(%p):", t);
    while(t) {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("\n");
}

void drop_linked_list(Node* head) {
    Node* t = head;
    while(t) {
        Node* p = t;
        t = t->next;
        printf("free %d\n", p->val);
        free(p);
    }
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("usage: %s %s %s\n", argv[0], "linked-list A size", "linked-list B size");
        exit(1);
    }

    int sizeA = atoi(argv[1]);
    int sizeB = (int)strtol(argv[2], (char **)NULL, 10);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    Node* pa = sorted_linked_list(sizeA);
    print_linked_list(pa);
    Node* pb = sorted_linked_list(sizeB);
    print_linked_list(pb);
    Node* p = merge(pa, pb);
    print_linked_list(p);
    drop_linked_list(p);
}
