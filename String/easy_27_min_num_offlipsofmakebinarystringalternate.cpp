//Most oprimized solution
//TC: O(S)
//SC:O(1)
int minFlips (string S)
{
    // your code here
    
    //for 010101...
    int ans1=0;
    for(int i=0;i<S.length();i++){
        if((i%2==0 && S[i]=='1') || (i%2!=0 && S[i]=='0'))
            ans1++;
    }
    
    //for 101010...
    int ans2=0;
    for(int i=0;i<S.length();i++){
        if((i%2==0 && S[i]=='0') || (i%2!=0 && S[i]=='1'))
            ans2++;
    }
    return min(ans1,ans2);
}
