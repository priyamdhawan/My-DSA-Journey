class Solution {
    private:
    bool detect(int node, int parent, vector<int> adj[], vector<int>& vis){

        vis[node] = 1;

        for( auto it : adj[node]){
            if(!vis[it]){

                if(detect(it, node, adj, vis) == true){
                    return true;
                }
            }

            else if( it != parent ){
                return true;
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
    vector<int> adj[V];
    int m = edges.size();
    // 2. Correctly build the graph from an Edge List
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V,0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                
                if(detect(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};