//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
   void topoSort(int c, vector<vector<pair<int, int>>> &adj, bool vis[], stack<int> &st){
	    vis[c] = true;
	    
	    for(auto x:adj[c]){
	        if(!vis[x.first]){
	            topoSort(x.first,adj,vis,st);
	        }
	    }
	    st.push(c);
	}
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        
        vector<vector<pair<int, int>>>  adj(N);
        
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        stack<int> st;
	    bool vis[N] = {false};
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i])
	            topoSort(0,adj,vis,st);
	    }
	   
	    
        
        vector<int> dis(N, INT_MAX);
        dis[0] = 0;
        while(!st.empty()){
            int t = st.top();
            
            for(auto x:adj[t]){
                int a = x.first;
                int b = x.second;
                
                dis[a] = min(dis[a] , b + dis[t]);
            }
            st.pop();
        }
        for(int i=0;i<N;i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends