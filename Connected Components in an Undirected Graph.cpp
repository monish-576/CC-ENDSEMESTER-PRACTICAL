class Solution {
  public:
    void dfs(int i, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& k) {
        vis[i] = 1;       
        k.push_back(i);
        
        for(int neighbor : adjList[i]) {
            if(vis[neighbor] == -1) {
                dfs(neighbor, adjList, vis, k);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> res;
        vector<int> vis(V, -1);
        vector<vector<int>> adjList(V);
        
       
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == -1) {
                vector<int> k;
                dfs(i, adjList, vis, k);
                
                res.push_back(k); 
            }
        }
        return res;
    }
};
