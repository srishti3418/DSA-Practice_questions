#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
};

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *createnode(int val){
    Node *root=new Node(val);
    root->left=NULL;
    root->right=NULL;
    return root;
}

int calculateindex(string str, int si, int ei){
    if(si>ei)
        return -1;

    stack<char> s;
    
    for(int i=si; i<=ei; i++){
        if(str[i]=='(')
            s.push(str[i]);
        else if(str[i]==')'){
            if(s.top()=='('){
                s.pop();
                if(s.empty())
                    return i;
            }
        }
    }
    return -1;
}

Node *treefromstring(string str, int si, int ei){
    if(si>ei)
        return NULL;
    
    Node *root=createnode(str[si]-'0');

    int index=-1;
    if(si+1<=ei && str[si+1]=='('){
        index = calculateindex(str, si+1, ei);
    }

    if(index!=-1){
        root->left=treefromstring(str, si+2, index-1);
        root->right=treefromstring(str, index+2, ei-1);
    }
    return root;
}

Node *treefromstring(string str, int *start){
    if(str.length()==0 || *start>=str.length())
        return NULL;
    
    int num=0;
    while(*start<str.length() && str[*start]!='(' && str[*start]!=')'){
        int num_int = str[*start]-'0';
        num = num*10 + num_int;
        *start++;
    }

    Node *root=createnode(num);

    if(*start>=str.length())
        return root;

    if(*start<str.size() && str[*start]=='('){
        *start++;
        root->left=treefromstring(str, *start);
    }

    if(*start<str.size() && str[*start]==')')
        *start++;

    if(*start<str.size() && str[*start]=='('){
        *start++;
        root->right=treefromstring(str, *start);
    }

    if(start<str.size() && str[start]==')')
        start++;

    return root;

}

int main(){
    string str = "4(2(3)(1))(6(5))";
    Node *root=treefromstring(str, 0, str.length()-1);
    inorder(root);
    cout<<endl;
    int start=0;
    Node *root2=treefromstring(str, &start);
    inorder(root2);
    cout<<endl;
}
