//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int s, int p , vector<int> adj[], bool vis[], bool path[]){
        vis[s] = true;
        path[s] = true;
        
        for(auto x:adj[s]){
            if(!vis[x]){
                // path[x] = true;
                if(dfs(x, s, adj, vis, path)){
                    return true;
                }
                // path[x] = false;
            }
            else if(path[x]){
                return true;
            }
        }
        path[s] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V], path[V];
        for(int i=0;i<V;i++){
            vis[i] = false;
            path[i] = false;
        }
        // vector<int> edge[V];
        // cout << adj[0].size() << endl;
        // for(int i=0;i<adj -> size();i++){
        //     edge[adj[i][0]].push_back(adj[i][1]);
        // }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis, path)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends