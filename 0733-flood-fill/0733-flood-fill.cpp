class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        // Edge case: If the starting pixel is already the new color, do nothing
        // This also prevents an infinite loop!
        if (originalColor == color) return image;
        
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        // Change color immediately upon pushing to queue
        image[sr][sc] = color; 
        
        // Your exact directional arrays
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // Check bounds and if the neighbor has the original color
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == originalColor) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color; // Update color
                }
            }
        }
        
        return image;
    }
};