class Solution {
private: 
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)){
                    return true;
                }
            }
            else if( pathVis[it]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // USING DFS TO DETECT CYCLE IN DIRECTED GRAPH

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        int n = prerequisites.size();


        for(int i = 0; i < n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < numCourses; i++){

            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true){  // MEANS CYCLE EXIST,  
                                                        // IF CYCLE EXIST SO CONDITION  WILL NOT MATCH   
                    return false;
                }
            }
        }
        return true;
    }
};