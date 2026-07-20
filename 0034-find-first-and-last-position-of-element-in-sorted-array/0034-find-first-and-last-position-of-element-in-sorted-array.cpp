class Solution {
    private:
    int first_index(vector<int>& arr,int n,int key) {

        int s = 0,e = n - 1;
        int mid = s + (e-s)/2;  // SAME AS (s+e)/2
        int ans = -1;
        while(s <= e){
            if (arr[mid] == key){
                ans = mid;
                e = mid - 1;   // important thing
            }

            if (arr[mid] < key){
                s = mid + 1;
            }

            if (arr[mid] > key ){
                e = mid -1;
            }
            mid = s + (e-s)/2;  
        }
        return ans;
    }


    int last_index(vector<int>& arr,int n,int key) {

        int s = 0,e = n - 1;
        int mid = s + (e-s)/2;  // SAME AS (s+e)/2
        int ans = -1;
        while(s <= e){
            if (arr[mid] == key){
                ans = mid;
                s = mid + 1;  // important thing
            }

            if (arr[mid] < key){
                s = mid + 1;
            }

            if (arr[mid] > key ){
                e = mid -1;
            }
            mid = s + (e-s)/2;  
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    
    int n = nums.size();

    vector<int>  p;
    p.push_back(first_index(nums,n,target));
    p.push_back(last_index(nums,n,target));

    return p;
    }
};