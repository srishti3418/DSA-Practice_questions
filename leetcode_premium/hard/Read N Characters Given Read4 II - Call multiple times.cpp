/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    int read_ptr=0;
    int cur_ptr=0;
    char buf4[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
      int curcharread=0;
        if(read_ptr!=cur_ptr){
           while(read_ptr<cur_ptr){ 
                buf[curcharread]=buf4[read_ptr];
                curcharread++;
                read_ptr++;
               if(curcharread==n)
                   return n;
           }
        }
        int charread=read4(buf4);
        
        read_ptr=0;
        cur_ptr=charread;
        
        while(charread>0 && curcharread<n){
            for(int i=0;i<charread;i++){
                buf[curcharread]=buf4[i];
                curcharread++;
                read_ptr++;
                
                if(curcharread==n)
                    return n;
                
            }
            charread=read4(buf4);
            read_ptr=0;
            cur_ptr=charread;
        }
    return curcharread;
    }
};