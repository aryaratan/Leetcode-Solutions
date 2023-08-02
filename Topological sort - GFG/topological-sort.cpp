//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	// top sort using DFS
	void dfs(int c, vector<int> adj[], bool vis[], stack<int> &st){
	    vis[c] = true;
	    
	    for(auto x:adj[c]){
	        if(!vis[x]){
	            dfs(x,adj,vis,st);
	        }
	        else{
	            continue;
	        }
	    }
	    st.push(c);
	}
	
	vector<int> bsf(int V, vector<int> adj[]){
	    vector<int> ans;
	    queue<int> q;
	    vector<int> inDeg(V,0);
	    unordered_map<int, int> mp;
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            mp[adj[i][j]]++;
	        }
	    }
	    
	   for(int i=0;i<V;i++){
	       inDeg[i] = mp[i];
	       if(mp[i] == 0){
	           q.push(i);
	       }
	   }
	    while(!q.empty()){
	        int t = q.front();
	        ans.push_back(t);
	        q.pop();
	        for(auto x:adj[t]){
	            inDeg[x]--;
	            if(inDeg[x] == 0){
	                q.push(x);
	            }
	        }
	    }
	   // for(auto x:ans){
	   //     cout << x << " ";
	   // }
	    return ans;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here

// an ordering of nodes(vertices) such that for every pair (u,v) having an edge u will appeare before v in that ordering.
	    
	    
	    // bsf Code
	    
	    return bsf(V,adj);
	    
	    
	    
	    // dfs code
	    /*
	    vector<int> ans;
	    stack<int> st;
	    bool vis[V] = {false};
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    */
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends