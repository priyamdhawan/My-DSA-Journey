class Solution {
    private:
        void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){

            vis[node] = 1;
            for(auto it : adj[node]){

                if(vis[it] == 0){
                    dfs(it, adj, vis);
                }
            }
        }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // making list from matrix
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        vector<int> vis(n,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){

            if(vis[i] == 0){
                cnt++;
                dfs(i,adj,vis);    
            }
        }

        return cnt;
    }
};