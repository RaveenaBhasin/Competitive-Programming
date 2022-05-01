class Solution {
public:
    void floodFiller(vector<vector<int>>&image, int currRow, int currCol, int m, int n, int currColor, int newColor){
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n || image[currRow][currCol] == newColor || image[currRow][currCol] != currColor){
            return;
        }
        image[currRow][currCol] = newColor;
        floodFiller(image, currRow-1, currCol, m, n, currColor, newColor);
        floodFiller(image, currRow+1, currCol, m, n, currColor, newColor);
        floodFiller(image, currRow, currCol-1, m, n, currColor, newColor);
        floodFiller(image, currRow, currCol+1, m, n, currColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int currColor = image[sr][sc];
        floodFiller(image, sr, sc, m, n, currColor, newColor);
        return image;
    }
};