#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//TC: O(nlogn)
//SC: O(1)
bool canPlaceCows(int arr[], int n, int c, int mid)
{
    int cnt = 1, coOr = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - coOr >= mid)
        {
            coOr = arr[i];
            cnt++;
        }
        if (cnt == c)
            return true;
    }
    return false;
}

int stallAllocation(int arr[], int n, int c)
{
    int low = 1, high = arr[n - 1] - arr[0];
    int res = INT_MIN;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPlaceCows(arr, n, c, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << stallAllocation(arr, n, c) << endl;
    }
}