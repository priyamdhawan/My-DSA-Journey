class Solution {
private:
    int Totaldays(vector<int>& weights, int days, int shipWeight){

        int total = 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){

            sum += weights[i];

            if( sum > shipWeight){
                total++;
                sum = weights[i];
            }
        }

        return total;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();

        int sum = 0;
        int maxWeight = -1;

        for(int i = 0 ; i < n; i++){
            sum += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }

        int s = maxWeight;  //The minimum capacity of the ship cannot be 1. It must be at least the weight of the heaviest single package in the array.
        int e = sum;
        int ans = -1;
        while(s <= e){

            int mid = s + (e - s)/2;

            if(Totaldays(weights, days, mid) <= days){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};