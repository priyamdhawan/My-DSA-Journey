class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0; // showing char array starting
        int ansIndex = 0;
        int n = chars.size();

        while (i < n){

            int j = i + 1;

            while(j<n && chars[j] == chars[i]){
                j++;
            }
            // yahan kab aaoge
            // ya tu pura vector traverse kardiya
            // ya to koi different character milgya

            // old char store karlo
            chars[ansIndex++] = chars[i];

            int count = j - i;  // IMPORTANT    

            if (count > 1){

                string cnt = to_string(count); // converting count to string like 12 = "12"
                for (char ch : cnt){

                    chars[ansIndex++] = ch;
                }
            }
            i = j;

        }
        return ansIndex;
    }
};