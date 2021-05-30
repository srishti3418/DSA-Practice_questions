//Most optimzed approach (horizontal scanning)
//TC: O(S), S is the sum of all characters in all strings
//SC: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output="";
        int n=strs.size();
        if(n<1)
            return output;
        if(n==1)
            return strs[0];
        string st=strs[0];
        int len=st.length();
        int k=0;
       for(int i=1;i<n && k<len;i++){
           string s=strs[i];
           if(st[k]==s[k]){
               if(i==n-1){
                   output += st[k];
                   k++;
                   i=0;
               }
           }
           else
               break;
       }
        return output;
    }
};
