#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void prevSmaller(vector<int> &vec, vector<int> &res, int n)
{
    if (n <= 1)
        return;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(vec[i]);
            continue;
        }
        while (!s.empty() && s.top() >= vec[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            s.push(vec[i]);
        }
        else if (s.top() < vec[i])
        {
            res[i] = s.top();
            s.push(vec[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    vector<int> res(n, -1);
    prevSmaller(vec, res, n);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}