class Solution {
private:
    int f(int ind, int n, vector<vector<int>>& dp){

        // Base case: The smallest piece length we can consider is 1.
        // If we fill the remaining 'n' with pieces of length 1, 
        // the product is 1 * 1 * 1... which is just 1.
        if(ind == 1){
            return 1;
        }

        if(dp[ind][n] != -1) return dp[ind][n];

        // If we DON'T take the piece, we don't multiply anything.
        // We just move to the next smaller length (ind - 1)
        int notTake = f(ind-1, n, dp);
        
        int take = 0;
        if(ind <= n){
            // If we TAKE the piece, we multiply 'ind' by the remaining product
            take = ind * f(ind, n - ind, dp);
        }

        return dp[ind][n] = max(take, notTake);
    }
public:
    int integerBreak(int n) {
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // Start from (n - 1) to ensure the number is broken into at least 2 parts
        return f(n - 1, n, dp);
    }
};