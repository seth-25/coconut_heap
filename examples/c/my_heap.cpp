#include "my_heap.h"

#include <queue>
using namespace std;

template <class T> struct cmp {
    bool operator() (const T& x, const T& y) const {return x.val > y.val;}
};

struct Node {
    float * ts;
    float val;
};

void* create_heap(){
    priority_queue<Node, vector<Node>, cmp<Node> >* heap = new priority_queue<Node, vector<Node>, cmp<Node> >();
//    priority_queue<int>* heap = new priority_queue<int>();
    return heap;
}

void heap_push(void* p, float *ts , float val){
    priority_queue<Node, vector<Node>, cmp<Node> >* heap = (priority_queue<Node, vector<Node>, cmp<Node> >*)p;
    struct Node node = {ts, val};
    heap->push(node);
}

void heap_pop(void* p){
    priority_queue<Node, vector<Node>, cmp<Node> >* heap = (priority_queue<Node, vector<Node>, cmp<Node> >*)p;
    return heap->pop();
}

float heap_top(void* p){
    priority_queue<Node, vector<Node>, cmp<Node> >* heap = (priority_queue<Node, vector<Node>, cmp<Node> >*)p;
    Node node = heap->top();
    return node.val;
}

int heap_size(void* p) {
    priority_queue<Node, vector<Node>, cmp<Node> >* heap = (priority_queue<Node, vector<Node>, cmp<Node> >*)p;
    return heap->size();
}

void delete_heap(void *p){
    delete (priority_queue<Node, vector<Node>, cmp<Node> >*)p;
}
