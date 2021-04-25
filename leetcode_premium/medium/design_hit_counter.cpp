//Naive approach: using queue data structure
//TC: O(N) beacuse in worst case we might have to remove all the entries from the queue
//SC: O(N)
class HitCounter {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
       while(!q.empty()){
           int diff=timestamp-q.front();
           if(diff>=300)
               q.pop();
           else
               break;
       }
    return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
