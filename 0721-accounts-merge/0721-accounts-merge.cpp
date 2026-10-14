class DisjointSet {
public:
    vector<int> parent,size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node) { 
        if (node == parent[node]) 
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    bool find(int u, int v) {
        if (findUPar(u) == findUPar(v)) {
            return true;
        }
        return false;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 

        if (ulp_u == ulp_v) return; 

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        
        int n = details.size();
        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < details[i].size(); j++){
                string mail = details[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()){  // if mail doesnt exist before
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergeMail[n];

        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);

            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0) continue;

            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;
            temp.push_back(details[i][0]);
            
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};