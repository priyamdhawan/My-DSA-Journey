class Solution {
    private:
    int Pivot(vector<int>& nums, int s, int e){
        int mid = s + (e-s)/2;

        while(s < e){
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else{  // nums[mid] < nums[n-1]
                e = mid;
            }
            mid = s + (e - s)/2;
        }
        return s;
    }

public:
    int findMin(vector<int>& nums) {
        // MINIMUM IN ROTATED SORTED ARRAY IS PIVOT ELEMENT 
        int n = nums.size();

        // IF THE ARRAY IS ONLY SORTED AND NOT ROTATED :-   
        if (nums[0] <= nums[n - 1]) {
            return nums[0];
        }

        int pivot = Pivot(nums, 0, n-1);

        return nums[pivot];
    }
};