class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.length();
        int m = p.length();

        int minLength = INT_MAX;
        int startIndex = -1;

        int cnt = 0;
        
        vector<int> hash(256,0);

        for(int i = 0; i < m; i++){
            hash[p[i]]++;
        }

        int l = 0;
        int r = 0;

        while( r < n){

            if(hash[s[r]] > 0){
                cnt++;
            }
            
            hash[s[r]]--;

            while(cnt == m){
                if( r - l + 1 < minLength){
                    minLength = r-l+1;
                    startIndex = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;

                l++;
            }
            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};