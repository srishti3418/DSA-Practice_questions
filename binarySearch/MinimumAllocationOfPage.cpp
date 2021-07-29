//TC: O(nlogn)
//SC: O(1)
bool isPossible(vector<int> &A, int B, int barrier, int n)
{
    int allotcated_std = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > barrier)
            return false;
        else if (pages + A[i] > barrier)
        {
            allotcated_std++;
            pages = A[i];
            if (allotcated_std > B)
                return false;
        }
        else
            pages += A[i];
    }
    return true;
}

int Solution::books(vector<int> &A, int B)
{
    int n = A.size();
    if (n < B)
        return -1;

    int low = A[0];
    int high = 0;
    int res = -1;
    for (auto i : A)
        high += i;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(A, B, mid, n))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
