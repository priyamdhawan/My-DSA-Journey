class Solution {
    private:
    void topo_dfs(int node, vector<pair<int,int>> adj[], int vis[], stack<int>& st){
    vis[node] = 1;

    for(auto it : adj[node]){
        int u = it.first;
        if(!vis[u]){
            topo_dfs(u, adj, vis, st);
        }
    }

    st.push(node);
}
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[n];
    
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
    }

    int vis[n] = {0};
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            topo_dfs(i, adj, vis, st);
        }
    }

    vector<int> dist(n, 1e9);

    dist[0] = 0;

    while(!st.empty()){

        int node = st.top();
        st.pop();

        for( auto it : adj[node]){
            int u = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[u]){
                dist[u] = dist[node] + wt;
            }
        }
    }
    // THE FIX: Replace unreachable distances (1e9) with -1
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1e9) {
            dist[i] = -1;
        }
    }
    return dist;
    }
};
