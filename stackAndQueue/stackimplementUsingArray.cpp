//TC: O(1) for all operations except printing which will take O(n)
//SC: O(n)
#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int i;
    int n;

public:
    stack(int size)
    {
        n = size;
        arr = new int[size];
        i = 0;
    }
    void push(int val)
    {
        if (i == n)
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[i++] = val;
        return;
    }
    void pop()
    {
        if (i == 0)
        {
            cout << "stack is empty, can't pop out" << endl;
            return;
        }
        i--;
        return;
    }
    bool isEmpty()
    {
        return i == 0;
    }
    int size()
    {
        return i;
    }
    int top()
    {
        if (i == 0)
        {
            cout << "No element is present, stack is empty" << endl;
            return -1;
        }
        int j = i;
        j--;
        return arr[j];
    }
    void print()
    {
        for (int j = 0; j < i; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    stack s(n);
    s.pop();
    s.push(3);
    if (s.isEmpty())
        cout << "stack is empty" << endl;
    s.push(4);
    s.push(1);
    s.push(6);
    s.push(10);
    cout << "Initial size " << s.size() << endl;
    s.pop();
    s.pop();
    s.push(8);
    cout << "Top element: " << s.top() << endl;
    cout << "Final size " << s.size() << endl;
    s.print();
}