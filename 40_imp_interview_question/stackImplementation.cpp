#include <iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int index=0;
        int size;

        Stack(int size){
            arr=new int[size];
            this->size=size;
        }

        void push(int data){
            if(index < this->size){
                arr[index]=data;
                index++;
            }
            else
                cout<<"Max limit of stack reached"<<endl;
        }

        void top(){
            cout<<"Top of the stack "<<arr[index-1]<<endl;
        }

        void pop(){
            if(index>0)
                index--;
            else
                cout<<"Stack is empty"<<endl;
        }

        void print(int size){
            for(int i=0; i<size; i++){
                cout<<arr[i]<<endl;
            }
        }

};

int main(){
    Stack *s=new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->pop();
    s->top();
    s->push(9);
    s->push(10);
    s->push(11);
    s->pop();
    s->push(12);
    s->top();
    s->print(5);

}