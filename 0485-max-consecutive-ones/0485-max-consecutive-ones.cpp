class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int prev = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 1){
                prev = 1;
            }
            else{
                prev = 0;
                cnt = 0;
            }

            if(nums[i] == 1 && prev == 1){
                cnt++;
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};