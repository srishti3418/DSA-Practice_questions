// return the Kth largest element in the given BST rooted at 'root'
//Most optimized solution
//TC: O(h+k)
//SC: O(h)
class Solution
{
    public:
    void kthLargest(Node *root, int K, int &index, int &res){
        if(root==NULL || index>=K)
            return;
        kthLargest(root->right, K, index, res);
        index++;
        if(index==K){
            res=root->data;
            return;
        }
            
        kthLargest(root->left, K, index, res);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        if(root==NULL)
            return -1;
        int index=0;
        int res=-1;
        kthLargest(root, K, index, res);
        return res;
    }
};
