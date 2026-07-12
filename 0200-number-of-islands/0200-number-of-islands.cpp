class Solution {
private: 
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){

        vis[row][col] = 1;
        queue<pair<int,int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        q.push({row,col});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                    
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; // FIXED: Assignment, not comparison
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};