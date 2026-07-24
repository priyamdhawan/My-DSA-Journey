class Solution {
public:
    string removeOccurrences(string s, string part) {
        // hint stack approach

        int n = s.size();

        
        string ans = "";

        for(int i = 0; i < n; i++){

            ans.push_back(s[i]);
                                                    // ans.size - part.size  will give substr of same length as part from last of ans
            if(ans.size() >= part.size() && ans.substr( ans.size() - part.size()) == part){    

                int x = part.size();
                while(x){
                    ans.pop_back();
                    x--;
                }
            }
        }

        return ans;
    }
};