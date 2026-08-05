class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int max = INT_MIN;
        int min = INT_MAX;

        map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            
            int digit = nums[i];
            
            // Store the digit as the key, and mark it as present (1)
            mp[digit] = 1;

            if(digit > max){
                max = digit;
            }

            if(digit < min) {
                min = digit;
            }
        }
        
        vector<int> ans;
        for(int j = min+1 ; j < max; j++){

            if(!mp[j]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};