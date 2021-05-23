//Most optimized solution
//TC: O(n)
//SC: O(1)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    stack<char> s;
    
    bool cpm(char a, char b){
        if((a==')' && b=='(') || (a=='}' && b=='{') || (a==']' && b=='['))
            return true;
        else
            return false;
    }
    
    bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        for(int i=0;i<n;i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='[')
                s.push(x[i]);
            else{
                if(s.empty() || !cpm(x[i],s.top())){
                    return false;
                }
                else
                    s.pop();
                    
            }
        }
        if(s.empty())
            return true;
        else
            return false;
    }

};
