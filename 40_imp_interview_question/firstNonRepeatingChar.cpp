#include <iostream>
using namespace std;

int firstUniqChar(string s) {
         int len=s.length();
         unordered_map<char, int> map;
         unordered_map<char,int> freq;
         for(int i=0;i<len;i++){
             map[s[i]]=i;
             freq[s[i]]++;
         }
        for(char cs:s){
            if(freq[cs]==1){
                return map[cs];
            }
        }
        return -1;
    }

int main() {
    cout<<firstUniqChar("leetcode")<<endl;
};