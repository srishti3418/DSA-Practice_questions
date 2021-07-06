
//TC: O(N^2)
//SC :O(N^2)
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    
	    if(x1==y1 && x2==y2)
	        return 0;
	    
	    int a[n][n];
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            a[i][j]=0;
	        }
	    }
	    queue<pair<int, int>> q;
	    q.push(make_pair(x1-1, y1-1));
	    while(!q.empty()){
	        auto curr=q.front();
	        int x=curr.first;
	        int y=curr.second;
	        
	        if(x-2>=0 && x-2<n && y+1>=0 && y+1<n && a[x-2][y+1]==0){
	            a[x-2][y+1]=a[x][y]+1;
	            q.push(make_pair(x-2, y+1));
	        }
	        if(x-1>=0 && x-1<n && y+2>=0 && y+2<n && a[x-1][y+2]==0){
	            a[x-1][y+2]=a[x][y]+1;
	            q.push(make_pair(x-1, y+2));
	        }
	        if(x+1>=0 && x+1<n && y+2>=0 && y+2<n && a[x+1][y+2]==0){
	            a[x+1][y+2]=a[x][y]+1;
	            q.push(make_pair(x+1, y+2));
	        }
	        if(x+2>=0 && x+2<n && y+1>=0 && y+1<n && a[x+2][y+1]==0){
	            a[x+2][y+1]=a[x][y]+1;
	            q.push(make_pair(x+2, y+1));
	        }
	        if(x+2>=0 && x+2<n && y-1>=0 && y-1<n && a[x+2][y-1]==0){
	            a[x+2][y-1]=a[x][y]+1;
	            q.push(make_pair(x+2, y-1));
	        }
	        if(x+1>=0 && x+1<n && y-2>=0 && y-2<n && a[x+1][y-2]==0){
	            a[x+1][y-2]=a[x][y]+1;
	            q.push(make_pair(x+1, y-2));
	        }
	        if(x-1>=0 && x-1<n && y-2>=0 && y-2<n && a[x-1][y-2]==0){
	            a[x-1][y-2]=a[x][y]+1;
	            q.push(make_pair(x-1, y-2));
	        }
	         if(x-2>=0 && x-2<n && y-1>=0 && y-1<n && a[x-2][y-1]==0){
	            a[x-2][y-1]=a[x][y]+1;
	            q.push(make_pair(x-2, y-1));
	        }
	        
	        q.pop();
	    }
	    return a[x2-1][y2-1];
	}
	
	
};
