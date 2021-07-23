#include <iostream>
#include <stack>
using namespace std;

//TC: O(N)
//SC: O(2N)
/*class queue
{
    stack<int> s1, s2;

public:
    void push(int val)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    void display()
    {
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << endl;
    }
};*/

//TC: O(N) (amortized O(1) complexity that is in most of the cases it'll be done in O(1))
//SC: O(2N)
class queue
{
    stack<int> input, output;

public:
    void push(int val)
    {
        input.push(val);
    }
    void pop()
    {
        if (!output.empty())
            output.pop();
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            output.pop();
        }
    }
    int top()
    {
        if (!output.empty())
            return output.top();
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
};

int main()
{
    queue q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(10);
    cout << "Top element: " << q.top() << endl;
    //q.display();
}