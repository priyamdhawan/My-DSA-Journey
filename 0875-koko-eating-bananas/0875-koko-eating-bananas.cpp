class Solution {
private:
    long long hours(vector<int>& piles, int mid){

        long long totalHours = 0;
        for(int i = 0; i < piles.size(); i++){

            totalHours += ceil( double(piles[i])/ double(mid));
        }

        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int maxi = -1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, piles[i]);
        }

        int s = 1;
        int e = maxi;
        int ans = -1;
        while(s <= e){

            int mid = s + (e -s)/2;

            if( hours(piles,mid) <= h){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};