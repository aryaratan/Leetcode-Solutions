//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
    // int dfs(int s, int e, int minDis,int curDis, vector<vector<int>> adj[],vector<int> &dp, bool vis[]){
    //     if(s == e){
    //         if(curDis == minDis){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(curDis > minDis){
    //         return 0;
    //     }
    //     vis[s] = true;
    //     if(dp[s] != -1){
    //         return dp[s];
    //     }
    //     int ans =0;
    //     for(auto x:adj[s]){
    //         if(!vis[x[0]]){
    //             ans += dfs(x[0], e,minDis, curDis +x[1],adj,dp,vis );
    //             ans = ans %md;
    //         }
    //     }
    //     dp[s] = ans;
    //     return ans;
    // }
  
  
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
         int md = 1000000007;
        vector<vector<int>> adj[n];
        for(auto r:roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<long> dist(n, LLONG_MAX);
         vector<int> dp(n, 0);
         dp[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long, int>, vector<pair<long, int>> , greater<pair<long, int>> > pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            long  d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                long cd = d + x[1];
                 if(cd < dist[x[0]]){
                    dist[x[0]] = cd;
                    // dist[x[0]] = 
                    dp[x[0]] = dp[node];
                    pq.push({cd,x[0]});
                }
                else if(cd == dist[x[0]]){
                    dp[x[0]] = (dp[x[0]] +  dp[node])%md;
                    
                }
                
            }
        }
        return dp[n-1]%md;
        // bool vis[n]={false};
        // int minDis = dist[n-1];
        // if(minDis == INT_MAX){
        //     return 0;
        // }
        
       
        // dfs(n-1, 0,minDis,0, adj, dp,vis);
        // return dp[n-1];
    }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends