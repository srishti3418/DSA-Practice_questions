
//Optimized approach
//TC: O(1)
//SC: O(N) where N is the size of the moving window
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int windowsize;
    double runningsum;
    MovingAverage(int size) {
            windowsize=size;
            runningsum=0.0;
        }
    
    double next(int val) {
        if(windowsize==q.size()){
            runningsum -= q.front();
            q.pop();
        }
        q.push(val);
        runningsum += val;
        double avg=(runningsum/q.size());
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
