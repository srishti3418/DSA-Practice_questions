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
		int getmin(){
			if(pq.size()==0)
				return 0;
			return pq[0];
			   }
		void insert(int element){
				pq.push_back(element);
				int childindex=pq.size()-1;
				while(childindex>0){
					int parentI=(childindex-1)/2;
					if(pq[childindex]<pq[parentI]){
						swap(pq[childindex],pq[parentI]);
									}
					else{
						break;
					     }
				childindex=parentI;
						   }
					   }
	int remove(){
		int LI=pq.size()-1;
		swap(pq[LI],pq[0]);
		int ans=pq[LI];
		pq.pop_back();
		int PI=0;
		int CI1=2*PI+1;
		int CI2=2*PI+2;
		while(CI1<LI){
			int CI;
			if(pq[CI1]>pq[CI2])
				CI=CI2;
			else
				CI=CI1;
			if(pq[PI]>pq[CI])
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
	p.insert(12);
	p.insert(6);
	p.insert(5);
	p.insert(100);
	p.insert(1);
	p.insert(9);
	p.insert(0);
	p.insert(14);
	cout<<p.remove()<<endl;
	cout<<p.remove()<<endl;
	cout<<"Size: "<<p.getsize()<<endl;
	cout<<"Empty Check:"<<p.isempty()<<endl;
	cout<<"Min:"<<p.getmin()<<endl;
	}
