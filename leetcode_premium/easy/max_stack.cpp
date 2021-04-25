
//NAive approach
//TC: O(N)
//SC: O(N)
class MaxStack {
public:
   
    stack<int> maxstack;
    stack<int> Stack;
    
    MaxStack() {
        
        }
    
    void push(int x) {
        int max;
        if(maxstack.empty()){
            max=x;
        }
        else{
            max=maxstack.top();
        }
        if(max>x){
            maxstack.push(max);
        }
        else{
            maxstack.push(x);
        }
        Stack.push(x);
        
    }
    
    int pop() {
        int p = Stack.top();
        maxstack.pop();
        Stack.pop();
        return p;
    }
    
    int top() {
        return Stack.top();
    }
    
    int peekMax() {
        return maxstack.top();
    }
    
    int popMax() {
        int max=peekMax();
        stack<int> buffer;
        while(top()!=max){
            buffer.push(pop());
            }
        pop();
        while(!buffer.empty()){
            int x=buffer.top();
            buffer.pop();
            push(x);
            
        }
        return max;
    }
};



/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
