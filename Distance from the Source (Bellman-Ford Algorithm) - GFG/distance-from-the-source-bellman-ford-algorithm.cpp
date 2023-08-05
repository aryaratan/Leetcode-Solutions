//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dis(V, 1e8);
        dis[S] = 0;
        
        for(int i=0;i<V;i++){
            vector<int> old = dis;
            
            for(auto e:edges){
                if(dis[e[0]] == INT_MAX){
                    continue;
                } 
                if(dis[e[0]] + e[2] < dis[e[1]]){
                    dis[e[1]] = dis[e[0]] + e[2];
                }
            }
            if(old == dis){
                return dis;
            }
        }
        
        for(auto e:edges){
            if(dis[e[0]] == INT_MAX){
                continue;
            } 
            if(dis[e[0]] + e[2] < dis[e[1]]){
                vector<int> ans = {-1};
                return ans;
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
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends