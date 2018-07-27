#include <iostream>
#include <array>

using namespace std;

const int MAX_SIZE  = 3;
const int EMPTY_INDEX = -1;

struct CircularQueue {
    array<int, MAX_SIZE> arr;
    int size = 0;
    int top, tail = EMPTY_INDEX;
};

int push(CircularQueue& c, int val)
{
    if (c.size == 3)
    {
        cout<<"It's full!"<<endl;
        return INT_MAX;
    }
    if (c.size == 0)
    {
        c.top = c.tail = 0;
    }
    else
    {
        c.tail++;
        c.tail = (c.tail) % MAX_SIZE;
    }
    c.arr[c.tail] = val;
    c.size++;
    return val;
}

int pop(CircularQueue& c)
{
    if (c.size == 0)
    {
        cout<<"It's empty!";
        return INT_MAX;
    }
    auto p = c.arr[c.top];
    c.top++;
    c.top = c.top % MAX_SIZE;
    c.size--;
    if (c.size == 0)
    {
        c.top = c.tail = EMPTY_INDEX;
    }
    return p;
}

void display(CircularQueue& c)
{
    cout<<"CircularQueue Status"<<endl;
    cout<<"size : "<<c.size<<" top : "<<c.top<<" tail : "<<c.tail<<endl;

    for (auto e: c.arr)
    {
        cout<<e<<' ';
    }
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    CircularQueue cq;
    push(cq, 1);
    display(cq);
    push(cq, 2);
    display(cq);
    push(cq, 3);
    display(cq);
    push(cq, 4);
    display(cq);
    
    cout<<"Pop : "<<pop(cq)<<endl;
    display(cq);
    
    cout<<"Pop : "<<pop(cq)<<endl;
    display(cq);
    
    cout<<"Pop : "<<pop(cq)<<endl;
    display(cq);
    
    cout<<"Pop : "<<pop(cq)<<endl;
    display(cq);
    
}
