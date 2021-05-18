//Most optimized solution
//TC: O(lengthofS)
//SC: O(1)
int isPlaindrome(char S[])
{
    // Your code goes here
    int len=0;
    while(S[len]!='\0'){
        len++;
    }
    int i=0;
    int j=len-1;
    while(i<j){
        if(S[i]==S[j]){
            i++;
            j--;
        }
        else
            return 0;
    }
    return 1;
}
