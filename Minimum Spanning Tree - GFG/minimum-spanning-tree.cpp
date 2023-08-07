//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        int sum = 0;
        priority_queue<vector<int> ,vector<vector<int>>, greater<vector<int>> > pq;
        
        vector<bool> vis(V, 0);
         
        pq.push({0,0,-1});
        
        
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            
            if(!vis[v[1]]){
                vis[v[1]] = true;
                sum += v[0];
                
                for(auto x:adj[v[1]]){
                    if(!vis[x[0]]){
                        pq.push({x[1], x[0], v[1]});
                    }
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends