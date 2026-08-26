class Solution {
public:
    // int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){

    //     // DOING 1- BASED INDEXING FOR TABULATION METHOD

    //     if( i == 0) return j;
    //     if(j == 0) return i;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(word1[i-1] == word2[j-1]){
    //         return dp[i][j] = 0 + f(i-1, j-1, word1, word2, dp);
    //     }
    //     else{
    //         return dp[i][j] = 1 + min( f(i, j-1, word1, word2, dp), min(f(i-1, j, word1, word2, dp), f(i-1, j-1, word1, word2, dp)));
    //                   //  inserting                deleting                      replacing    -- 3 methods
    //     }
    // }


    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // SPACE OPTIMIZATION

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0; j <= m; j++){
            prev[j] = j; // base case
        }

        for(int i = 1; i <= n; i++){

            curr[0] = i; // base case
            for(int j = 1; j <= m; j++){

                 if(word1[i-1] == word2[j-1]){
                    curr[j] = 0 + prev[j-1];
                }
                else{
                    curr[j] = 1 + min( curr[j-1], min(prev[j], prev[j-1]));
                            //  inserting                deleting                      replacing    -- 3 methods
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};