#include <iostream>
#include <cmath>
using namespace std;

//TC: O(((10^d)*n)*m)
int multiply(double mid, int m)
{
    double ans = 1.0;
    for (int i = 1; i <= m; i++)
    {
        ans *= mid;
    }
    return ans;
}

double findnthRoot(int n, int m)
{
    double low = 1;
    double high = n;
    double eps = 1e-5;
    double mid;
    while ((high - low) >= eps)
    {
        mid = (high + low) / 2.0;
        if (multiply(mid, m) < n)
            low = mid;
        else
            high = mid;
    }
    return mid;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << findnthRoot(n, m) << endl;
    cout << pow(n, (double)(1.0 / (double)m)) << endl;
}