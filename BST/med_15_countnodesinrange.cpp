//Most optimized solution
//TC: O(h+k)
//SC: O(h)
int getCount(Node *root, int l, int h)
{
  // your code goes here  
  if(root==NULL)
    return 0;
  if(root->data==l && root->data==h)
    return 1;
 
  if(root->data>=l && root->data<=h)
    return 1+getCount(root->left, l, h)+getCount(root->right, l, h);
  if(l<root->data)
    return getCount(root->left, l, h);
  else
    return getCount(root->right, l, h);
}
