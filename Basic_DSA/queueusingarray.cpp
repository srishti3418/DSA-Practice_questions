#include<iostream>
using namespace std;

template <typename T>
class queue{
	T*data;
	int nextindex;
	int size;
	int firstindex;
	int capacity;
	public:
		queue(int totalsize){
			data=new T[totalsize];
			nextindex=0;
			size=0;
			firstindex=-1;
			capacity=totalsize;
				    }
		int getsize(){
			return size;
			   }
		bool isempty(){
			return firstindex==-1;
			      }
		void enqueue(T element){
			if(size==capacity){
				//cout<<"Queue is full"<<endl;
				//return;
				T*newdata=new T[2*capacity];
				int j=0;
				for(int i=firstindex;i<capacity;i++){
					newdata[j]=data[i];
					j++;
								     }
				for(int i=0;i<firstindex;i++){
					newdata[j]=data[i];
					j++;
							     }
				nextindex=capacity;
				firstindex=0;
				
					  }
			data[nextindex]=element;
			nextindex=(nextindex+1)%capacity;
			size++;
			if(firstindex==-1){
				firstindex=0;
					  }
					}
		T dequeue(){
			if(firstindex==-1){
				cout<<"Queue is empty!"<<endl;
				return 0;
					  }
			T ans=data[firstindex];
			firstindex=(firstindex+1)%capacity;
			size--;
			return ans;
			   }
		T front(){
			if(isempty()){
				cout<<"Queue is empty!"<<endl;
				return 0;
				     }
			return data[firstindex];
			  }
		};

int main(){ 
	queue<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.front()<<endl;

	cout<<q.getsize()<<endl;
	if(q.isempty()){
		cout<<"True"<<endl;
			}
	else{
		cout<<"False"<<endl;
	    }
	}
