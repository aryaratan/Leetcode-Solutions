//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
    bool dfs(int c, vector<int> adj[], bool vis[], bool path[]){
        vis[c] = true;
        path[c] = true;
        
        for(auto x:adj[c]){
            if(!vis[x]){
                if(!dfs(x,adj,vis,path)){
                    return false;
                }
                
            }
            else if(path[x]){
                return false;
            }
        }
        path[c] = false;
        return true;
    }
    
    vector<int> bsf(int V, vector<int> adj[]){
	    vector<int> ans;
	    queue<int> q;
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            inDeg[adj[i][j]]++;
                
	        }
	    }
	    
	   for(int i=0;i<V;i++){
	       if(inDeg[i] == 0){
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
	
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        //code here
        
        vector<int> adj[N];
	    
	    for(int i=0;i<P;i++){
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    
	    
	    bool vis[N]={false} , path[N]={false};
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(!dfs(i,adj,vis,path)){
	                vector<int> temp;
	                return temp;
	            }
	        }
	    }
	    
	    
	    return bsf(N,adj);
	    
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends