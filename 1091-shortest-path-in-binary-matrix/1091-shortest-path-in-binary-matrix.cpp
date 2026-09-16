class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        int path = INT_MAX;
        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0},1});
        grid[0][0] = 1; // FIX 1: Mark the starting cell as visited

        int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        int ans = INT_MAX;

        while(!q.empty()){

            int row = q.front().first.first;
            int col = q.front().first.second;

            int path = q.front().second;
            q.pop();

            if(row == n-1 && col == m-1){
                ans = min(path, ans);
                continue;
            }

            for(int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0){
                    q.push({{nrow, ncol}, path+1});
                    grid[nrow][ncol] = 1; // FIX 2: Mark as visited immediately to avoid infinite loops
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};