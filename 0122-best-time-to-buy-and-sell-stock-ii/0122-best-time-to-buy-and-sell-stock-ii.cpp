class Solution {
public:

    long f(int ind, int buy, vector<int>& prices, vector<vector<long>> &dp){

        int n = prices.size();
        if(ind == n) return 0;
        
        if( dp[ind][buy] != -1) return  dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max( (-prices[ind] + f(ind+1, 0, prices, dp)) , (0 + f(ind+1, 1, prices, dp)) );
        }
        else{   // sell
            profit = max( (prices[ind] + f(ind+1, 1, prices, dp)), ( 0 + f(ind+1, 0, prices, dp)));
        } 

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();      
        vector<vector<long>> dp(n, vector<long>(2,-1));

        return f(0, 1, prices, dp);
    }
};