#include<vector>
class Solution {
public:
   
    vector<vector<int>> highFive(vector<vector<int>>& items) {
       
         if(items.size()==0)
            return items;
        vector<vector<int>> result;
        sort(items.begin(),items.end());
        int x=items[0][0];
        vector<int> vec;
        int k=0;
        for(int i=0;i<items.size();i++){
           if(items[i][0]==x){
               vec.push_back(items[i][1]);
           }
            else{
                int sum=0;
                sort(vec.begin(),vec.end(),greater<int> ());
                for(int j=0;j<5;j++){
                    sum += vec[j];
                }
                int avg = sum/5;
                result[k].push_back(x);
                result[k].push_back(avg);
                k++;
                if(i==items.size())
                    break;
                x=items[i][0];
                for(int j=vec.size()-1;j>=0;j--){
                    vec.pop_back();
                }
                i--;
            }
            }
        return result;
        
    }
};
