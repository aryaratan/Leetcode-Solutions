//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void minDis(int src, vector<int> adj[], int N, bool vis[], vector<int> &dis){
        queue<pair<int, int>> q;
        q.push({src,0});
        dis[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for(auto x:adj[node]){
                
                if(!vis[x]){
                    dis[x] = d+1;
                    vis[x] = true;
                    q.push({x,d+1});
                }
            }
        }
        return ;
    }
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int> adj[N];
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> dis(N, INT_MAX);
        dis[src] = 0;
        bool vis[N] = {false};
        vis[src] = true;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                minDis(src, adj, N,vis,dis);
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i] == INT_MAX)
                dis[i] = -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends