class DisjointSet {
public:
    // To store the rank of each node
    vector<int> rank;
    
    /* To store the size of components 
    that each node belongs to */
    vector<int> size;
    
    // To store the ultimate parent of each node
    vector<int> parent;
    
    // Constructor
    DisjointSet(int n) {
        
        // Resize the arrays
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1, 1);
        // Initialise each node with its own value
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    /* Helper function to find ultimate
    parent along with path compression */
    int findUPar(int node) {
        // Base case
        if (node == parent[node])
            return node;
            
        // Backtracking step for path compression
        return parent[node] = findUPar(parent[node]);
    }
    
    /* Function to detemine if two nodes 
    are in the same component or not */
    bool find(int u, int v) {
        // Return true if both have same ultimate parent 
        return (findUPar(u) == findUPar(v));
    }
    
    /* Function to perform union of 
    two nodes based on ranks */
    void unionByRank(int u, int v) {
        
        // Get the ultimate parents of both nodes
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // Return if nodes already belong to the same component
        if (ulp_u == ulp_v) return;
        
        /* Otherwise, join the node to the other 
        node having higher ranks among the two */
        if (rank[ulp_u] < rank[ulp_v]) {
            // Update the parent
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            // Update the parent
            parent[ulp_v] = ulp_u;
        }
        
        /* If both have same rank, join any node to the 
        other and increment the rank of the parent node */
        else {
            // Update the parent
            parent[ulp_v] = ulp_u;
            
            // Update the rank
            rank[ulp_u]++;
        }
    }
    
    /* Function to perform union of 
    two nodes based on ranks */
    void unionBySize(int u, int v) {
        
        // Get the ultimate parents of both nodes
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // Return if nodes already belong to the same component
        if (ulp_u == ulp_v) return;
        
        /* Otherwise, join the node belonging to the smaller 
        component to the node belonging to bigger component */
        if (size[ulp_u] < size[ulp_v]) {
            // Update the parent
            parent[ulp_u] = ulp_v;
            
            // Update the size 
            size[ulp_v] += size[ulp_u];
        }
        else {
            // Update the parent
            parent[ulp_v] = ulp_u;
            
            // Update the size
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DisjointSet ds(n);
        for(auto it: connections){
            int u = it[0], v = it[1];

            ds.unionByRank(u, v);
        }

        int cnt=0;
        for(int i=0;i<n;++i){

            if(ds.parent[i] == i) cnt++;
        }

        return cnt-1;
    }
};