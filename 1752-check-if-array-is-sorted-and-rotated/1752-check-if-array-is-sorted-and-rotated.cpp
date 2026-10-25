class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int i = 1;
        int cnt = 0;

        while(i < n){

            if(nums[i-1] > nums[i]){
                cnt++;
            }
            i++;
        }

        if(nums[n-1] > nums[0]){
            cnt++;
        }

        if(cnt == 1 || cnt == 0) return true;
        
        return false;
    }
};