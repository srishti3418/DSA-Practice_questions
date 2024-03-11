#include <iostream>
using namespace std;

bool isPalindrome(string s) {
       int len = s.length()-1;
       int i=0, j=len;
       while(i<j){
           while(i<j && !isalnum(s[i]))
            i++;
           while(i<j && !isalnum(s[j]))
            j--;
           if(tolower(s[i])!=tolower(s[j]))
            return false;
           i++;
           j--;
       }
       return true;
    }

int main(){
    cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
}