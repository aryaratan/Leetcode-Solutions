//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<pair<int, int>> q;
         vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
         if(vis[i] == false){
           
        q.push({i,-1});
       
        vis[i] = true;
        while(!q.empty()){
            // int s = q.size();
            
            // while(s--){
                pair<int, int> p = q.front();
                q.pop();
                
                for(auto x:adj[p.first]){
                    if(vis[x] && p.second != x){
                        return true;
                    }
                    if(!vis[x]){
                         vis[x] = true;
                    q.push({x, p.first});
                    }
                   
                }
            // }
        }
            
         } 
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends