class Solution {
public:
    int smallestNumber(int n, int t) {
        
        if(n < 10){
            while(true){

                if(n == 10) return 10; // base case
                if(n%t == 0) return n;
                else n++;
            }
        }

        if(n == 100) return n;

        else{
            int newNum = n;

            while(true){
                int digit1 = newNum % 10;
                int digit2 = newNum / 10;

                if((digit1 * digit2) % t == 0) return newNum;

                else{
                    newNum++;
                }
            }
        }
    }
};