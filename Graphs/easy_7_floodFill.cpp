//TC: O(n*m)
//TC: O(n*m) {Recursive calls}

class Solution {
public:
    void floodFill(int i, int j, vector<vector<int>> &images, int newColor, int n, int m, int color){
        
        if(images[i][j]==color){
            images[i][j]=newColor;
            if(i+1<n && images[i+1][j]==color)
                floodFill(i+1, j, images, newColor, n, m, color);
            if(j-1>=0 && images[i][j-1]==color)
                floodFill(i, j-1, images, newColor, n, m, color);
            if(j+1<m && images[i][j+1]==color)
                floodFill(i, j+1, images, newColor, n, m, color);
            if(i-1>=0 && images[i-1][j]==color)
                floodFill(i-1, j, images, newColor, n, m, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        
        int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        if(color!=newColor)
            floodFill(sr, sc, image, newColor, n, m, color);
        return image;
        
    }
};