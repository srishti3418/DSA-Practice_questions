#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	vector<int>::iterator it=v.begin();
	v.erase(it,it+5);
	//v.pop_back();
	while(it!=v.end()){
		cout<<*it<<" ";
		it++;
			   }
	cout<<endl;
	unordered_map<string,int> ourmap;
	ourmap["abc"]=1;
	ourmap["def"]=2;
	ourmap["ghi"]=3;
	ourmap["jkl"]=4;
	ourmap["lmn"]=5;
	ourmap["opq"]=6;
	cout<<ourmap.find("abc");
	//cout<<ourmap.find("opq")<<endl;
	/*unordered_map<string,int>::iterator it1=ourmap.begin();
	ourmap.erase(it1);
	while(it1!=ourmap.end()){
		cout<<"Value of the index "<<it1->first<<"is "<<it1->second<<endl;
		it1++;
				}*/
	}
