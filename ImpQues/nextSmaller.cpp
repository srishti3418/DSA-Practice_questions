//Most optimized solution
//TC: O(n)
//SC: O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

void nextsmaller(vector<int> &res, vector<int> &vec, int n)
{
    if (n <= 1)
        return;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
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
            continue;
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
    nextsmaller(res, vec, n);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}