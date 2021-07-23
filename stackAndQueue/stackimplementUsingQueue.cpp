#include <iostream>
#include <queue>
using namespace std;

//stack implementation using 2 queues
//TC: O(N)
//SC: O(2N)
/*class stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val)
    {
        q2.push(val);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        q1.pop();
    }
    void display()
    {
        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
        cout << endl;
    }
};*/

//stack implementation using single queue
//TC: O(N)
//SC: O(N)
class stack
{
    queue<int> q;

public:
    void push(int val)
    {
        q.push(val);
        for (int i = 0; i < q.size() - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    void pop()
    {
        q.pop();
    }
    void display()
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
};

int main()
{
    stack s;
    s.push(3);
    s.push(6);
    s.push(1);
    s.pop();
    s.display();
}
