//This is done by two traversal of arrays (not so optimal)
//TC: O(n)
//SC: O(1)
/*int getNthFromLast(struct Node *head, int n)
{
  int len=0;
  struct Node *temp=head;
  while(temp!=NULL){
      len++;
      temp=temp->next;
  }
  if(n>len)
    return -1;
  int count=len-n+1;
  temp=head;
  int i=1;
  while(i!=count){
      temp=temp->next;
      i++;
  }
  return temp->data;
}*/

//Most optimized solution (only one traversal)
//TC: O(n)
//SC: O(1)
int getNthFromLast(struct Node *head, int n)
{
  struct Node *main_ptr=head;
  struct Node *ref_ptr=head;
  
  if(head==NULL)
    return -1;

  int count=0;
  while(count<n){
      if(ref_ptr==NULL)
        return -1;
      ref_ptr=ref_ptr->next;
      count++;
  }
  
  
  while(ref_ptr!=NULL){
      main_ptr=main_ptr->next;
      ref_ptr=ref_ptr->next;
  }
  return main_ptr->data;
  
}
