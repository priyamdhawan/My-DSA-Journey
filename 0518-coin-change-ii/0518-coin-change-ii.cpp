class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        // FIX: Use 'unsigned int'. It will safely wrap around on massive intermediate 
        // dead-ends without crashing your program.
        vector<vector<unsigned int>> dp(n, vector<unsigned int> (amount+1, 0));

        // TABULATION METHOD

        // base cases
        // (Removed dp[0][0] = 1 because the loop handles it when i = 0)
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= amount; target++){

                // FIX: Match the 'unsigned int' type
                unsigned int notTake = dp[ind -1][target];

                unsigned int take = 0;
                if(coins[ind] <= target){
                    take = dp[ind][target - coins[ind]];
                }

                dp[ind][target] = take + notTake;
            }
        }

        // It is completely safe to cast back to int at the end!
        return (int)dp[n-1][amount];
    }
};