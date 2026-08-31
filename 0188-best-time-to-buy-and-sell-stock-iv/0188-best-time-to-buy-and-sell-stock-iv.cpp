class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // TABULATION METHOD
        // SPACE OPTIMIZATION

       vector<vector<int>> after(2, vector<int>(k+1,0));
       vector<vector<int>> curr(2, vector<int>(k+1,0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind] + after[0][cap] , 0 + after[1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + after[1][cap-1] , 0 + after[0][cap]);
                    }

                   curr[buy][cap] = profit;
                }
            }
            after = curr;
        }

        return after[1][k];
    }
};