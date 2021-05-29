//Most optimized solution
//TC: O(n)
//SC: O(1)
int countRev (string s)
{
    // your code here
    int n=s.length();
    if(n & 1)
        return -1;
    int cl=0,op=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='{')
            op++;
        else
            cl++;
        if(cl>op){
            res += cl-op;
            swap(op,cl);
        }
    }
    res += abs(cl-op)/2;
    return res;
    
}
