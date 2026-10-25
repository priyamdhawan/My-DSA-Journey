class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Handle empty array edge case
        if (nums.empty()) return 0;
        
        // 'j' represents the index where the next unique element should be placed.
        // The first element is always unique, so we start j at 1.
        int j = 1; 
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's a new unique element
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i]; // Place it at the correct position
                j++;               // Increment the position tracker
            }
        }
        
        // 'j' is now the count of unique elements
        return j; 
    }
};