class Solution {
private:
    // Notice we now pass currentSum and the final target separately
    int f(int ind, vector<int>& nums, int currentSum, int target, vector<vector<int>>& dp, int offset) {
        
        // BASE CASE: We have processed all numbers
        if (ind == -1) {
            // Did our running sum hit the target?
            if (currentSum == target) return 1;
            return 0; 
        }

        // Check memoization table
        if (dp[ind][currentSum + offset] != -1) {
            return dp[ind][currentSum + offset];
        }

        // CHOICE 1: Assign a '+' sign
        int addChoice = f(ind - 1, nums, currentSum + nums[ind], target, dp, offset);

        // CHOICE 2: Assign a '-' sign
        int subChoice = f(ind - 1, nums, currentSum - nums[ind], target, dp, offset);

        // Store and return
        return dp[ind][currentSum + offset] = addChoice + subChoice;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int totalSum = 0;
        for (int i = 0; i < n; i++) totalSum += nums[i];

        // Edge case: If the absolute value of the target is greater than the 
        // sum of all elements, it's physically impossible to reach.
        if (abs(target) > totalSum) return 0;

        // DP array size is safe because currentSum will never exceed totalSum
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        // Start recursion with currentSum = 0
        return f(n - 1, nums, 0, target, dp, totalSum);
    }
};