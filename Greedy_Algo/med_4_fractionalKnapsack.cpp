//TC: O(nlogn)
//SC: O(1)
bool comp(Item i1, Item i2)
{
    double r1 = ((double)i1.value / (double)i1.weight);
    double r2 = ((double)i2.value / (double)i2.weight);
    return r1 > r2;
}
class Solution
{
public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        sort(arr, arr + n, comp);
        for (int i = 0; i < n; ++i)
        {
            if (arr[i].weight <= W)
            {
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                ans += ((double)arr[i].value / (double)arr[i].weight) * ((double)(W));
                break;
            }
        }
        return ans;
    }