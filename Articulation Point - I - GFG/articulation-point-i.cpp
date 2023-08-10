//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   void dfsHelper(int c, int p, vector<int> adj[],set<int> &ans ,vector<bool> &vis, vector<int> &steps, vector<int> &low, int times){

        vis[c] = true;
        steps[c] = times ;
        low[c] = times;
        times++;
        int x = 0;
        for(auto a:adj[c]){
            if( a == p ){
                continue;
            }
            if(!vis[a]){
                dfsHelper(a, c, adj,ans, vis, steps, low, times);
                low[c] = min(low[c], low[a]);
                if(p != -1 && steps[c] <= low[a] ){
                    ans.insert(c);
                    // ans.insert(c);
                }
                x++;
            }
            else{
                low[c] = min(low[c], steps[a]);
            }
            
                
        }
        if(x >= 2 && p ==-1 ){
            ans.insert(c);
        }
        return ;
    }

  
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> steps(n);
        vector<int> low(n);
        
        set<int> ans;
        vector<bool> vis(n , false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsHelper(0, -1, adj, ans,vis, steps, low,1);
            }
        }
            
        // if(adj[0].size() > 1){
        //     ans.insert(0);
        // }
        vector<int> sol(ans.begin(), ans.end());
        
        if(sol.size() == 0){
            sol.push_back(-1);
        }
        return sol;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends