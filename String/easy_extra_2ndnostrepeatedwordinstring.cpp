//Most opytimized solution

class Solution
{
  public:
    unordered_map<string,int> mp;
    string secFrequent (string arr[], int n)
    {
        //code here.
        if(n<=2)
            return arr[0];
        int mx=INT_MIN;
        int sec_max=INT_MIN;
        for(int i=0;i<n;i++){
             mp[arr[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
           
            if(it->second>mx){
                sec_max=mx;
                mx=it->second;
            }
            else if (it->second>sec_max && sec_max!=mx)
                sec_max=it->second;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==sec_max)
                return it->first;
        }
        
    }
};
