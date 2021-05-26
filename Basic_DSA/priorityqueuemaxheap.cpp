#include<iostream>
#include<vector>
using namespace std;

class priorityqueue{
	vector<int> pq;
	public:
		priorityqueue(){
				}
		bool isempty(){
			return pq.size()==0;
				}
		int getsize(){
			return pq.size();
				}
		int getmax(){
			if(pq.size()==0)
				return 0;
			return pq[0];
				}
		void insert(int element){
			pq.push_back(element);
			int CI=pq.size()-1;
			while(CI>0){
				int PI=(CI-1)/2;
				if(pq[PI]<pq[CI])
					swap(pq[PI],pq[CI]);
				else	
					break;
				CI=PI;
				   }
					}
		int remove(){
			if(pq.size()==0)
				return 0;
			int LI=pq.size()-1;
			swap(pq[LI],pq[0]);
			int ans=pq[LI];
			pq.pop_back();
			int PI=0;
			int CI1=2*PI+1;
			int CI2=2*PI+2;
			while(CI2<LI){
				int CI;
				if(pq[CI1]>pq[CI2])
					CI=CI1;
				else
					CI=CI2;
				if(pq[PI]<pq[CI])
					swap(pq[PI],pq[CI]);
				else
					break;
				PI=CI;
				CI1=2*PI+1;
				CI2=2*PI+2;
				   }
			return ans;
				}
		};

int main(){
	priorityqueue p;
	int choice;
	cin>>choice;
	while(choice!=-1){
		switch(choice){
			case 1:
				int element;
				cin>>element;
				p.insert(element);
				break;
			case 2:
				cout<<"size:"<<p.getsize()<<endl;
				break;
			case 3:
				cout<<"Check Empty:"<<p.isempty()<<endl;
				break;
			case 4:
				cout<<"Max:"<<p.getmax()<<endl;
				break;
			case 5:
				cout<<"Removed max:"<<p.remove()<<endl;
				break;
			default:
				return 0;
			  }
		cin>>choice;
		}
	}
