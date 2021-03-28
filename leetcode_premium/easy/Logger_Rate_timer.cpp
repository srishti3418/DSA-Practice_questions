class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> ourmap;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
  
    //Most optimized solution using hasmap
    //Time complexity: O(1)
    //Space complexity: O(n) where n is the number of messages
    bool shouldPrintMessage(int timestamp, string message) {
        if(ourmap.find(message)==ourmap.end()){
            ourmap[message]=timestamp+10;
            return true;
        }
        else{
            if(timestamp<ourmap[message])
                return false;
            else{
                ourmap[message] = timestamp + 10;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
