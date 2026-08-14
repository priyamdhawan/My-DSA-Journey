class Solution {
private:
    int f(int ind, vector<int>& nums, int target, vector<unordered_map<int, int>>& dp) {
        
        // BASE CASE
        if (ind == -1) {
            if (target == 0) return 1;
            return 0; 
        }

        // Check if we already calculated the answer for this specific target at this index.
        // We use .count() to see if the key exists in the map.
        // target can be negative, and the map handles it perfectly!
        if (dp[ind].count(target)) {
            return dp[ind][target];
        }

        // CHOICE 1: Assign a '+' (target decreases)
        int addChoice = f(ind - 1, nums, target - nums[ind], dp);

        // CHOICE 2: Assign a '-' (target increases)
        int subChoice = f(ind - 1, nums, target + nums[ind], dp);

        // Store the result in the map and return
        return dp[ind][target] = addChoice + subChoice;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // dp is an array of 'n' HashMaps.
        // We don't need totalSum, offsets, or size calculations anymore!
        vector<unordered_map<int, int>> dp(n);

        return f(n - 1, nums, target, dp);
    }
};