//TC: O(n)
//SC: O(n)
class Solution
{
public:
    bool checkForOpenP(char c, stack<char> &stk)
    {
        char top = stk.top();
        if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '['))
        {
            stk.pop();
            return true;
        }
        else
            return false;
    }

    bool isValid(string s)
    {
        int n = s.length();
        stack<char> stk;
        for (int i = 0; i < n; i++)
        {
            if (stk.empty())
            {
                if (s[i] == ')' || s[i] == '}' || s[i] == ']')
                    return false;
                stk.push(s[i]);
            }
            else
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    stk.push(s[i]);
                else
                {
                    if (checkForOpenP(s[i], stk))
                        continue;
                    else
                        return false;
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};