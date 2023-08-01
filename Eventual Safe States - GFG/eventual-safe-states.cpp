//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    // bool dfs(int c, vector<int> adj[], bool vis[], bool path[], vector<int> &ans){
    //     vis[c] = true;
    //     path[c] = true;
    //     ans[c] = 0;
    //     for(auto x:adj[c]){
    //         if(!vis[x]){
    //             if(dfs(x,adj,vis,path,ans)){
    //                 return true;
    //             }
    //         }
    //         else if(path[x]){
    //             return true;
    //         }
    //     }
        
    //     path[c] =false;
    //     ans[c] = 1;
    //     // st.insert(c);
    //     return false;
        
    // }
    
    bool dfsCheck(int node, vector<int> adj[], int vis[],
 int pathVis[], 
        int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}
  
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        set<int> st;
      int ans[V] = {0};
        int vis[V] = {0};
        int path[V] = {0};
        //         memset(path, false ,V);
        // memset(vis, false ,V);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                
                
                dfsCheck(i,adj,vis,path,ans);
            }
        }
        // sort(ans.begin(), ans.end());
        vector<int> sol;
        for(int i=0;i<V;i++){
            if(ans[i] == 1){
                sol.push_back(i);
            }
        }
        // vector<int> ans(st.begin(), st.end());
        return sol;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends