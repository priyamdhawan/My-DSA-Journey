class Solution {
private:
    int f(int ind, int n){

        if(ind == 1 ){
            return 1;
        }

        int notTake = 1 * f(ind-1, n);
        int take = 0;
        if(ind <= n){
            take = ind * f(ind, n - ind);
        }

        return max(take, notTake);
    }
public:
    int integerBreak(int n) {
        return f(n-1, n);
    }
};