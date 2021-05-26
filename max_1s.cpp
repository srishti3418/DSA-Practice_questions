#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_one(int n){
    int k=n;
    vector<int> v;
    if(k==0){
        return k;
    }
    while(k!=0){
        v.push_back(k%2);
        k=k/2;
    }
    vector<int> Max;
    for(int i=0;i<v.size();i++){
        int count=0;
        if(v[i]==0){
                i++;
            }
        while(i<v.size() && v[i]!=0){
                count++;
                i++;
        }
       Max.push_back(count);
    }
    int MAX=INT_MIN;
    for(int i=0;i<Max.size();i++){
        if(Max[i]>MAX){
            MAX=Max[i];
        }
    }
    return MAX;
}

int main()
{
    int n;
    cin >> n;
    int ans= max_one(n);
    cout<<ans<<endl;
    return 0;
}

