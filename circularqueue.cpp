#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>

using namespace std;

struct Queu
{
    int rear,first;
    int *q;
    int size;
    Queu(int num)
    {
        this->size = num;
        q = new int[size];
        first = rear = -1;
    }

    void enq(int num)
    {
        if(first == -1 && rear == -1) // empty queue
        {
            first = rear = 0;
            q[rear] = num;
        }
        else if((first == 0 && rear == size-1) || first == rear + 1) // full queue
            cout<<"overflow"<<endl;
        else if(first != 0 && rear ==size-1) // when empty spaces are at 0,1... postion
        {
            rear = 0;
            q[rear] = num;
        }
        else // normal insertion
        {
            rear +=1;
            q[rear] = num;
        }
    }

    int deq()
    {
        if(first == -1) // empty queue
            cout<<"Underflow"<<endl;
        else if(first == rear) // only one element deleted
            first = rear = -1;
        else if(first == size -1 && first != rear) // last element is front and to delete last element front must point to 0 in that case
            first = 0;
        else // normal deletion
            first +=1;
    }

    void display()
    {
        if(first == -1) // empty queue
            cout<<"Queue Empty"<<endl;

        if(rear>=first) // elements are ordered linearly
            for(int i=first; i<=rear; i++)
                cout<<q[i]<<endl;
        else // elements are ordered circularly
        {
            for(int i=first; i<size; i++)
                cout<<q[i]<<endl;
            for(int i=0; i<=rear; i++)
                cout<<q[i]<<endl;
        }
    }
};

int main()
{
    Queu q(5);

    q.enq(1);
    q.enq(2);
    q.enq(3);
    q.enq(4);

    q.display();

    q.deq();
    q.deq();
    q.display();

    q.enq(5);
    q.enq(6);
    q.enq(7);
    q.display();

    q.enq(8);
    return 0;
}
