#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long int sum_N = (n * (n + 1)) / 2;
    long long int sum_sq = (n * (n + 1) * (2 * n + 1)) / 6;
    long long int missingno = 0, repeatingno = 0;

    for (int i = 0; i < n; i++)
    {
        sum_N -= (long long int)arr[i];
        sum_sq -= (long long int)arr[i] * (long long int)arr[i];
    }

    missingno = (sum_N + (sum_sq / sum_N)) / 2;

    repeatingno = missingno - sum_N;

    cout << "missingno :" << missingno << endl;
    cout << "repeatingno :" << repeatingno << endl;
}