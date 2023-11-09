#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 1000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isempty()
    {
        if (front == rear)
        {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int data)
    {
        if(rear == size)
        {
            cout << "queue is full" << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear)
            {
                front = 0;
                rear = 0;
            }
        return ans;
        }

    }

    int front1()
    {
        if(front == rear)
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }
};

int main()
{
    Queue q;
    cout << "Queue is empty: " << (q.isempty() ? "true" : "false") << endl;
    q.enqueue(45);
    q.enqueue(56);
    q.enqueue(78);
    q.enqueue(34);
    q.enqueue(98);

    cout << "Dequeued value is: " << q.dequeue() << endl;

    cout << "Front element is: " << q.front1() << endl;

    cout << "Dequeued value is: " << q.dequeue() << endl;

    cout << "Front element is: " << q.front1() << endl;
    cout << "Dequeued value is: " << q.dequeue() << endl;

    cout << "Front element is: " << q.front1() << endl;
    cout << "Dequeued value is: " << q.dequeue() << endl;

    cout << "Front element is: " << q.front1() << endl;
    cout << "Dequeued value is: " << q.dequeue() << endl;

    cout << "Front element is: " << q.front1() << endl;
}

