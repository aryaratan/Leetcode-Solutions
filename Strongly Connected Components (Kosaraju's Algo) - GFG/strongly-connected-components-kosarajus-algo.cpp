//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
// 	vector<int> parents;
	
// 	int ultPar(int u){
// 	    if(u == ultPar(u)){
// 	        return u;
// 	    }
// 	    return parents[u] = ultPar(parents[u]);
// 	}
	
// 	int connect(int u, int v){
// 	    int up = ultPar(u);
// 	    int vp = ultPar(v);
	    
	    
// 	    if(up == vp){
// 	        return ;
// 	    }
// 	    parents[up] = vp;
// 	}
	
	
	void dfs(int c, vector<vector<int>>& edges, vector<bool> &vis, stack<int> &st){
	    vis[c] = true;
	    
	    for(auto x:edges[c]){
	        if(!vis[x]){
	            dfs(x, edges, vis, st);
	        }
	    }
	    st.push(c);
	    return;
	}
	
    int kosaraju(int V, vector<vector<int>>& edges)
    {
        //code here
        
        stack<int> st;
        vector<bool> vist(V, false);
        for(int i=0;i<V;i++){
            if(vist[i] == false)
                dfs(i, edges, vist, st);
        }
        
        
        
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(auto x:edges[i]){
                adj[x].push_back(i);
            }
        }
        
        
        
        
        vector<bool> vis(V, false);
        int scc = 0;
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(!vis[i]){
                // cout << i << endl;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int s = q.size();
                    
                    while(s--){
                        int t = q.front();
                        
                        for(auto x:adj[t]){
                            // cout << x << endl;
                            if(!vis[x]){
                                vis[x] = true;
                                q.push(x);
                            }
                        }
                        q.pop();
                    }
                    
                    
                }
                scc++;
            }
        
            
        }
        
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends