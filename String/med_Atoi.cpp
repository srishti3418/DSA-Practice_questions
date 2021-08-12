//TC: O(n)
//SC: O(1)
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int j = 0;
        int sign = 1;
        while (s[j] == ' ')
            j++;
        if (s[j] == '-')
        {
            sign = -1;
            j++;
        }
        else if (s[j] == '+')
        {
            j++;
        }
        long long ans = 0;
        for (; j < n; j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                ans = ans * 10 + s[j] - '0';
                if (ans > INT_MAX && sign == 1)
                    return INT_MAX;
                else if (-ans < INT_MIN && sign == -1)
                    return INT_MIN;
            }
            else
                break;
        }
        return ans * sign;
    }
};