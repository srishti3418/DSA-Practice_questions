class Solution {
public:
    //Brute force approach, M1
    //TC: O(n^2)
    //SC: O(1)
    /*bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return true;
        for(int i=0;i<intervals.size();i++){
            for(int j=i+1;j<intervals.size();j++){
             if((intervals[j][0]>=intervals[i][0] && intervals[j][0]<intervals[i][1]) || (intervals[i][0]>=intervals[j][0] && intervals[i][0]<intervals[j][1])){
                   return false;
               }
            }
        }
        return true;
    }*/
    
    //Optimized approach(involve sorting), M2
    //TC: O(nlogn)
    //SC: O(1)
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return true;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0])
                return false;
        }
        return true;
    }
    
};
