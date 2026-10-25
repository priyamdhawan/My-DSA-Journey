class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = s+1;

        while(e < n){

            if(nums[s] == 0 && nums[e] != 0){
                swap(nums[s],nums[e]);
                s++;
                e++;
            }
            else if(nums[s] != 0){
                s++;
                if(s == e){
                e++;
                }
            }
            else{
                e++;
            }
        }
    }
};