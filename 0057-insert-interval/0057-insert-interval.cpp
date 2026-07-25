class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        while (i < n && intervals[i][0] < newInterval[0]){
            
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        if(ans.empty() || ans.back()[1] < newInterval[0]){
            ans.push_back(newInterval);
        }

        else if(ans.back()[1] >= newInterval[0]) {   
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
        }
        

        // same logic as merge overlapping interval
        while(i < n){
            
            if( ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
            else{  // if arr[i][0] < ans.back()[1]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            i++;
        }

        return ans;
    }
};