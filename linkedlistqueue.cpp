
#include <iostream>

using namespace std;

struct Item {
    int val;
    Item* next;
};

struct Queue {
    int size = 0;
    Item* top, *tail = nullptr;
};
void enqueue(unique_ptr<Queue>& q, int val);
void display(unique_ptr<Queue>& q);
void init(unique_ptr<Queue>& q);
int dequeue(unique_ptr<Queue>& q);

int main(int argc, const char * argv[])
{
    auto q = make_unique<Queue>();
    init(q);
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    
    display(q);
    
    cout<<"dequeue: "<<dequeue(q)<<endl;
    display(q);
    cout<<"dequeue: "<<dequeue(q)<<endl;
    display(q);

}

void init(unique_ptr<Queue>& q) {
    q->size = 0;
    q->top = q->tail = nullptr;
}

void enqueue(unique_ptr<Queue>& q, int val)
{
    auto item = new(Item){.val=val, .next=nullptr};
    q->size++;
    if (q->top==nullptr)
    {
        q->tail = q->top = item;
        return;
    }
    q->tail->next = item;
    q->tail = q->tail->next;
}
int dequeue(unique_ptr<Queue>& q)
{
    if (q->top == nullptr) {
        return INT_MAX;
    }
    q->size--;
    auto item = q->top;
    q->top = q->top->next;
    return item->val;
}
void display(unique_ptr<Queue>& q)
{
    cout<<"Queue Size: "<<q->size<<endl;
    auto cur = q->top;
    while(cur)
    {
        cout<<cur->val<<' ';
        cur = cur->next;
    }
    cout<<endl;
}
