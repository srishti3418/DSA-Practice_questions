 //Brute force solution
//TC: O(n)
//SC: O(k)
/*class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    void kthSmallestElement(Node *root, int K, int &index, int &res){
        if(root==NULL || index>=K)
            return;
        kthSmallestElement(root->left, K, index, res);
        index++;
        if(index==K){
            res=root->data;
            return;
        }
        kthSmallestElement(root->right, K, index, res);
    }
    
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        if(root==NULL)
            return -1;
        int index=0;
        int res=-1;
        kthSmallestElement(root, K, index, res);
        return res;
    }
};*/

//Better solution using augmented tree data structure
//TC: O(h)
//SC: O(h)
/*class Solution{
  public:
    // Return the Kth smallest element in the given BST
    int lcount(Node *root){
        if(root==NULL)
            return -1;
        return lcount(root->left)+1;
    }
    
    Node *kthSmallestElement(Node *root, int K){
        if(root==NULL)
            return NULL;
        int count=lcount(root)+1;
        if(count==K)
            return root;
        if(count>K)
            return kthSmallestElement(root->left, K);
        return kthSmallestElement(root->right, K-count);
            
    }
    
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        if(root==NULL)
            return -1;
        Node *res=kthSmallestElement(root, K);
        return res->data;
    }
};*/

//Optimized solution (using Morris traversal)
//TC: O(n)
//SC: O(1)
class Solution{
  public:
    // Return the Kth smallest element in the given BST

    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        Node *curr=root;
        int count=0;
        while(curr!=NULL){
            if(curr->left==NULL){
                count++;
                if(K==count)
                    return curr->data;
                curr=curr->right;
            }
            else{
                Node *pre=curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                    pre=pre->right;
                if(pre->right==NULL){
                    pre->right=curr;
                    curr=curr->left;
                }
                else{
                    count++;
                    if(K==count)
                        return curr->data;
                    pre->right=NULL;
                    curr=curr->right;
                }
            }
        }
        if(count!=K)
            return -1;
    }
};
