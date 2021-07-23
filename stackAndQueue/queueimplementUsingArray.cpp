#include <iostream>
#include <climits>
using namespace std;

class queue
{
    int front;
    int rear;
    int *arr;
    int capacity;
    int size;

public:
    queue(int n)
    {
        capacity = n;
        arr = new int[n];
        front = 0;
        rear = 0;
        size = 0;
    }
    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "queue is full" << endl;
            return;
        }
        rear = rear % capacity;
        arr[rear++] = val;
        size++;
        return;
    }
    void dequeue()
    {
        if (size == 0)
        {
            cout << "can't dequeue, queue is empty" << endl;
            return;
        }
        front = front % capacity;
        front++;
        size--;
    }
    int Size()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int Front()
    {
        if (size == 0)
        {
            cout << "queue is empty" << endl;
            return INT_MIN;
        }
        return arr[front];
    }
};

int main()
{
    int n;
    cin >> n;
    queue q(n);
    if (q.isEmpty())
        cout << "queue is empty" << endl;
    //cout << "Initial size: " << q.Size() << endl;
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(7);
    q.dequeue();
    q.enqueue(5);
    q.enqueue(9);
    q.dequeue();
    q.dequeue();
    cout << "Front element: " << q.Front() << endl;
    cout << "Final size: " << q.Size() << endl;
}