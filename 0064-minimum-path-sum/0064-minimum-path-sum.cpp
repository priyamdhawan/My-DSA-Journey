class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m,-1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(i == 0 && j == 0) dp[i][j] = grid[i][j];

                else{
                    int up = INT_MAX/2;
                    int left = INT_MAX/2;

                    if(i > 0){
                        up = grid[i][j] + dp[i-1][j];
                    }
                    if(j > 0){
                        left = grid[i][j] + dp[i][j-1];
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n-1][m-1];
    }
};