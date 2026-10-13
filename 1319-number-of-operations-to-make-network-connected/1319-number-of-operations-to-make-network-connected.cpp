class DisjointSet {
public:
    vector<int> parent,size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,0);

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
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int count = 0; // countiing for extra edges 
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.find(u,v)){       // union karne se phele check karna , if connected before then this is extra edge
                count++;      
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int cntC = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cntC++;
            }
        }

        int ans = cntC - 1;

        if(count >= ans){
            return ans;
        }
        return -1;


    }
};