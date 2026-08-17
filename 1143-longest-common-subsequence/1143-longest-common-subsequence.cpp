class Solution {
private:
    int f(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){

        if(ind1 == 0 || ind2 == 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(text1[ind1-1] == text2[ind2-1]){
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, text1, text2, dp);
        }

        return dp[ind1][ind2] = 0 + max(f(ind1-1, ind2, text1, text2, dp), f(ind1, ind2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f( n, m, text1, text2, dp);
    }
};