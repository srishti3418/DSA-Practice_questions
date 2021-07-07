//TC: 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> myset;
        bool isPresent=false;
        
        for(int i=0; i<wordList.size(); i++){
            if(endWord.compare(wordList[i])==0)
                isPresent=true;
            myset.insert(wordList[i]);
        }
        
        if(isPresent==false)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty()){
            
            depth += 1;
            int lsize=q.size();
            while(lsize--){
                
                string curr=q.front();
                q.pop();
                
                for(int i=0; i<curr.length(); i++){
                     string temp=curr;
                     for(char c='a'; c<='z'; c++){
                         temp[i]=c;
                         if(temp.compare(curr)==0)
                             continue;
                         if(temp.compare(endWord)==0)
                             return depth+1;
                         if(myset.find(temp)!=myset.end()){
                             q.push(temp);
                             myset.erase(temp);
                         }
                     }
                }
                
            }
        }
        return 0;
    }
};