class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.
        
        // SPACE OPTIMIZATION METHOD

        vector<bool> prev(k+1, 0), curr(k+1, 0);

        prev[0] = curr[0] = true;  // bcoz for anyone the target 0 has to be true
        // base case
        
        if(arr[0] <= k) prev[arr[0]] = true;


        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= k; target++){
                // copy same stuff done in recursion
                bool notTake = prev[target];

                bool take = false;
                if(arr[ind] <= target){
                    take = prev[target - arr[ind]];
                }

                curr[target] = take || notTake;
            }
            prev = curr;
        }

        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalsum = 0;
        for(int i = 0; i < n ; i++) totalsum += nums[i];

        if(totalsum % 2 != 0) return false;

        int target = totalsum / 2;

        return subsetSumToK(n, target, nums);
    }
};