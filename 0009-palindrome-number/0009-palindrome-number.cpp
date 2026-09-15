class Solution {
public:
    bool isPalindrome(int x) {
        // Base case 1: Negative numbers are never palindromes (e.g., -121 != 121-)
        // Base case 2: Numbers ending in 0 cannot be palindromes unless the number is exactly 0
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        
        // Keep extracting the last digit of x and adding it to reversedHalf
        // We know we've reached the middle when x is less than or equal to reversedHalf
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + (x % 10);
            x /= 10;
        }
        
        // If the length of the number is even, x will exactly equal reversedHalf (e.g., 1221 -> 12 == 12)
        // If the length is odd, reversedHalf will have the middle digit, so we divide by 10 to drop it (e.g., 12321 -> 12 == 123 / 10)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};