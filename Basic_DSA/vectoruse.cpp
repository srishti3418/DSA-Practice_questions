#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
	v.push_back(10);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(20);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(30);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(40);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(50);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.push_back(60);
	cout<<"Cap:"<<v.capacity()<<endl;
	cout<<"Size:"<<v.size()<<endl;
	v.pop_back();
	v.pop_back();
	v.pop_back();
	cout<<endl;
	cout<<"Size:"<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "<<v.at(i)<<endl;
				    }
	cout<<"Cap:"<<v.capacity()<<endl;}
