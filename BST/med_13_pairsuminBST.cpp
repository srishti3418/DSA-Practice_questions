//Brute force approach
//TC: O(m+n) where m and n are the sizes of the trees
//SC: O(m+n) 
void inorder(Node *root, vector<int> &vec){
    if(root==NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    vector<int> res1, res2;
    inorder(root1, res1);
    inorder(root2, res2);
    int n1=res1.size();
    int n2=res2.size();
    int i=0, j=n2-1;
    int count=0;
    while(i<n1 && j>=0){
        if(res1[i]+res2[j]==x){
            i++;
            j--;
            count++;
        }
        else if(res1[i]+res2[j]<x)
            i++;
        else
            j--;
    }
    return count;
    
}*/

//One more solution exist which to similar to brute force approach only we
//'ll not be using vector space instead for every element of tree1 we'll
//search (x-a) in tree2.
//TC: O(m*h)
//SC: O(m*h). (??)

//Most optimized solution
//TC: O(m+n)
//SC: O(h1+h2)
int countPairs(Node* root1, Node* root2, int x){
    if(root1==NULL || root2==NULL)
        return 0;
    
    stack<Node *> st1;
    stack<Node *> st2;
    int count=0;
    while(1){
        
        while(root1!=NULL){
            st1.push(root1);
            root1=root1->left;
        }
        while(root2!=NULL){
            st2.push(root2);
            root2=root2->right;
        }
        
        if(st1.empty() || st2.empty())
            break;
        
        Node *top1=st1.top();
        Node *top2=st2.top();
        
        if(top1->data+top2->data==x){
            count++;
            st1.pop();
            st2.pop();
            
            root1=top1->right;
            root2=top2->left;
        }
        else if(top1->data+top2->data<x){
            st1.pop();
            root1=top1->right;
        }
        else{
            st2.pop();
            root2=top2->left;
        }
        
    }
    return count;
}
