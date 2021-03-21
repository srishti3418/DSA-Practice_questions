/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    //Method 1 involving internal buffer buf4
    /*int read(char *buf, int n) {
       int readchars=4, copychars=0;
        char buf4[4];
        while(copychars<n && readchars==4){
            readchars=read4(buf4);
            for(int i=0;i<readchars;i++){
                if(copychars==n)
                    return copychars;
                buf[copychars]=buf4[i];
                copychars++;
            }
        }
        return copychars;
    }*/
    
    //Method 2, direct copy to main buffer(no need of internal buffer)
    int read(char * buf, int n){
        int readchars=4, copychars=0;
        while(copychars<n && readchars==4){
            readchars=read4(buf+copychars);
            copychars += readchars;
        }
        return min(n,copychars);
    }
};
