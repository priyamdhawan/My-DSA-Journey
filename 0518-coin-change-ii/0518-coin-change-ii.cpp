class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<unsigned int> prev(amount+1, 0), curr(amount+1, 0); 

        prev[0] = 1;
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
        }

        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= amount; target++){

                unsigned int notTake = prev[target];

                unsigned int take = 0;
                if(coins[ind] <= target){
                    take = curr[target - coins[ind]];
                }

                curr[target] = take + notTake;
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};