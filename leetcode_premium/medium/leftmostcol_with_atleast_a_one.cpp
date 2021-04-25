/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * 
 */

/*class BinaryMatrix {
   public:
      int get(int row, int col);
      vector<int> dimensions();
    
      vector<int> dimensions(){
          
      }
    
      int get(int row,int col){
          
      }
  };*/


//Naive approach(but better than linear search approach)
//TC: O(n*logm) where n is the number of rows and n is the number of columns in each row
//SC: O(1)
/*class Solution {
public:
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        int smallestcols=v[1];
        for(int i=0;i<v[0];i++){
            int low=0;
            int high=v[1]-1;
            while(low<high){
                int mid=(low+high)/2;
                if(binaryMatrix.get(i,mid)==0){
                    low=mid+1;
                }
                else{
                    high=mid;
                }
            }
            if(binaryMatrix.get(i,low)==1){
                smallestcols=min(smallestcols,low);
            }
            
        }
        if(smallestcols==v[1])
            return -1;
        else
            return smallestcols;
    }
};*/


//Most optimized solution: Using two pointer approach
//TC: O(M+N)
//SC: O(1)
class Solution {
public:
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        int cols=v[1];
        int rows=v[0];
        int currentrow=0;
        int currentcol=cols-1;
        while(currentrow<rows && currentcol>=0){
            if(binaryMatrix.get(currentrow,currentcol)==0)
                currentrow++;
            else
                currentcol--;
        }
        if(currentcol==cols-1)
            return -1;
        else
            return currentcol+1;
    }
};
