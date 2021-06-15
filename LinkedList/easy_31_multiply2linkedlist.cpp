//Most optimized solution
//TC: O(n)
//SC: O(1)
#define mod 1000000007 
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  Node *temp1=l1;
  Node *temp2=l2;
  long long a=0, b=0;
  
  while(temp1!=NULL){
      a =((a*10)%mod + (temp1->data)%mod)%mod;
      temp1=temp1->next;
  }
  while(temp2!=NULL){
      b = ((b*10)%mod +(temp2->data)%mod);
      temp2=temp2->next;
  }
  long long result=(a%mod*b%mod)%mod;
  return result;
}
