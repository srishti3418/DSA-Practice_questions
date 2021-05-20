class Solution {
public:
    
    //Brute force approach
    //TC: O(n^2)
    //SC: O(1)
    /*int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        if(n<1)
            return 0;
        if(n==1)
            return arr[0];
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            int area=arr[i];
            int j=i-1;
            for(;j>=0;j--){
                if(arr[j]>=arr[i])
                    area=(i-j+1)*arr[i];
                else{
                    if(area<arr[i])
                        area=arr[i];
                    break;
                }
            }
            j++;
            for(int k=i+1;k<n;k++){
                if(arr[k]>arr[i])
                    area=(k-j+1)*arr[i];
                else{
                    if(area<arr[i])
                        area=arr[i];
                    break;
                }
            }
            if(area>maximum)
                maximum=area; 
        }
        return maximum;
    }*/
    
    
    //Most optimized solution
    //TC: O(n)
    //SC: O(n)
    int largestRectangleArea(vector<int>& hist) {
        int n=hist.size();
        stack<int> s; 
  
        int max_area = 0;  
        int tp;  
        int area_with_top; 

        int i = 0; 

        //traversing the array.
        while (i < n) 
        { 
            //if current bar is greater than or equal to bar on top 
            //of stack, we push the index into stack. 
            if (s.empty() || hist[s.top()] <= hist[i]) 
                s.push(i++); 

            //if current bar is lower than bar on top of stack, we calculate
            //area of rectangle with top of stack as the smallest bar.  
            //i is rightindex for top and element before top in stack is leftindex
            else
            { 
                tp = s.top();  
                //popping the top element of stack.
                s.pop();  

                //calculating the area with hist[tp] stack as smallest bar. 
                area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 

                //updating maximum area, if needed. 
                if (max_area < area_with_top) 
                    max_area = area_with_top; 
            } 
        } 

        //now popping the remaining bars from stack and calculating 
        //area with every popped bar as the smallest bar.
        while (s.empty() == false) 
        { 
            tp = s.top(); 
            s.pop(); 

            area_with_top=hist[tp]*(s.empty()? i :i-s.top()-1); 

            //updating maximum area, if needed. 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
        //returning the maximum area.
        return max_area; 
    }
};
