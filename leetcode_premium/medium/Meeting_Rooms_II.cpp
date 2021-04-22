/*void swap(int *x, int *y);
class MinHeap
{
    public:
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
  
    int parent(int i) { return (i-1)/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
  
    // to extract the root which is the minimum element
    int extractMin();
  
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
  
    // Inserts a new key 'k'
    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
  
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
  
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

  
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
  
*/


/*class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       if(intervals.size()==0)
           return 0;
        if(intervals.size()==1)
            return 1;
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       //MinHeap h(n);
        priority_queue<int, vector<int>, greater<int>> pq;
       for(int i=0;i<n;i++){ 
            //if(h.heap_size == 0){
                h.insertKey(intervals[i][1]);
                continue;
            //}
           if(pq.empty()){
                pq.push(intervals[i][1]);
                continue;
            }
            int minimum=pq.top();
            if(minimum>intervals[i][0]){
                pq.push(intervals[i][1]);
            }
           else{
               pq.pop();
               pq.push(intervals[i][1]);
           }
           
       }
        return pq.size();
    }
}; 
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       if(intervals.size()==0)
           return 0;
        if(intervals.size()==1)
            return 1;
       int n=intervals.size();
       int start[n];
       int end[n];
       for(int i=0;i<n;i++){
           start[i]=intervals[i][0];
       }
       for(int i=0;i<n;i++){
           end[i]=intervals[i][1];
       }
       sort(start,start+n);
       sort(end,end+n);
       int count=0;
       int i=0;
       int j=0;
       while(i<n){
           if(start[i]<end[j]){
               count++;
               i++;
           }
           else{
               i++;
               j++;
           }
       }
     return count;
    }
};
//All the approaches are optimal and will take O(nlogn) time and O(n) space.
//Naive approach which is not mentioned above (in which we'll check for free room every time) will have time complexity O(n^2) and O(1).
