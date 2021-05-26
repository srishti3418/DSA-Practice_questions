#include<iostream>
using namespace std;

class dynamicarray{
	//int*data;
	int nextindex;
	int capacity;
	public:
		int*data;
		dynamicarray(){
			data=new int[5];
			nextindex=0;
			capacity=5;
			      }
	/*	void addelement(int n){
			if(nextindex==capacity){
				cout<<"New memory got created of double capacity!"<<endl;
				int*newdata=new int[2*capacity];
				for(int i=0;i<nextindex;i++){
					newdata[i]=data[i];
							    }
				delete [] data;
				data=newdata;
				capacity*=2;
						}
			data[nextindex]=n;
			nextindex++;
					}*/
		void add(int i,int element){
			if(i<nextindex){
				data[i]=element;
				nextindex++;
					}
			else if(i==nextindex){
				int*datanew=new int[2*capacity];
				for(int j=0;j<nextindex;j++){
					datanew[j]=data[j];
							    }
				delete [] data;
				data=datanew;
				capacity*=2;
				nextindex++;
					    }
			else
				return;
						}
		void print(){
			for(int i=0;i<nextindex;i++){
				cout<<data[i]<<" ";
						    }
			cout<<endl;
			    }	
		int get(int i){
			if(i<nextindex)
				return data[i];
			else
				return -1;
				}	
		 };

int main(){
	/*(dynamicarray d1;
	d1.addelement(10);
	d1.addelement(20);
	d1.addelement(30);
	d1.addelement(40);
	d1.addelement(50);
	d1.addelement(60);
	d1.print();
	cout<<"Give the index number:"<<endl;
	int s;
	cin>>s;
	int ans=d1.get(s);
	cout<<ans<<endl;*/
	int i,element;
	cout<<"Enter the index and the corresponding element:"<<endl;
	cin>>i>>element;
	dynamicarray d2;
	d2.add(i,element);
	d2.print();
		}
