//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i] == -1){
	            queue<int> q;
        	    q.push(i);
        	   // vector<bool> vis(V, false);
        	   // vis[0] = true;
        	    
        	    
        	    color[i] = 0;
        	    while(!q.empty()){
        	        int cn = q.front();
        	       // int cc = q.front().second;
        	        q.pop();
        	        for(int x:adj[cn]){
        	            if(color[x] == -1){
        	                color[x] = !color[cn];
        	                q.push(x);
        	               // vis[x] = true;
        	            }
        	            else if(color[cn] == color[x]){
        	                return false;
        	            }
        	        }
        	    }
	        }
	    }
	    
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends