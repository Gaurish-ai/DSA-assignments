#include<iostream>
using namespace std;
#define MAX 100
class Queue
{
    int arr[MAX];
    int front,rear;
    public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }
    bool isFull()
    {
        return(rear==MAX-1);
    }
    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"overflow condition";
        }
        if(isEmpty())
        {
            front=rear=0;
        }
        else
        {
            rear++;
            arr[rear]=x;
            cout<<x<<"enqueued";
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout<<arr[front]<<"dequeued";
        if(front==rear)
        {
            front=rear-1;
        }
        front=front+1;
}
int peek()
{
    if(isEmpty())
    {
        cout<<"empty queue";
        return -1;
    }
    
    return arr[front];
}
  void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue(); 

    return 0;
}