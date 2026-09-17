class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({v,time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        vector<int> minTime(n+1,1e9);
        minTime[k] = 0;

        while(!pq.empty()){

            int curTime = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();

            for( auto it : adj[node]){
                int adjNode = it.first;
                int edgeTime = it.second;

                if(curTime + edgeTime < minTime[adjNode]){
                    minTime[adjNode] = curTime + edgeTime;
                    pq.push({curTime + edgeTime, adjNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < minTime.size(); i++){
            if(minTime[i] == 1e9) return -1;
            else{
                ans = max(ans, minTime[i]);
            }
        }  

        return ans;      
    }
};