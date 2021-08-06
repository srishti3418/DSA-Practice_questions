//TC: O(n)
//SC: O(n)
class Solution
{
public:
    bool checkIfPermutationExist(string &temp)
    {
        int n = temp.size();
        int index1, index2;
        int i = n - 2;
        for (; i >= 0; i--)
        {
            if (temp[i] < temp[i + 1])
            {
                index1 = i;
                break;
            }
        }
        if (i == -1)
            return false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (temp[i] > temp[index1])
            {
                index2 = i;
                break;
            }
        }
        swap(temp[index1], temp[index2]);
        reverse(temp.begin() + index1 + 1, temp.end());
        return true;
    }

    int nextGreaterElement(int n1)
    {
        string temp = to_string(n1);

        bool ans = checkIfPermutationExist(temp);
        size_t res = stoll(temp);
        if (!ans || res > INT_MAX)
            return -1;
        else
            return res;
    }
};