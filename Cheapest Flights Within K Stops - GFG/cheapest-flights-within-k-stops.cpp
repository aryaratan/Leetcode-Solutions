//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        vector<pair<int, int>> adj[n];
        
        for(auto x:flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> price(n , INT_MAX);
        price[src] = 0;
        // priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        queue<vector<int>> pq;
        pq.push({0,src});
        int i =0;
        while(!pq.empty() && i <= K){
            
            
            
            int s = pq.size();
            // if(c == dst){
            //     return d;
            // }
            while(s--){
              int d = pq.front()[0];
                int c = pq.front()[1];
                
                // int d = pq.top()[0];
                // int c = pq.top()[1];
                // cout << c << endl;
                pq.pop();
                for(auto x:adj[c]){
                    // cout << x.first << " " << x.second << endl;
                    if(x.second + d < price[x.first]){
                        price[x.first] = x.second + d;
                        pq.push({price[x.first], x.first});
                        // if(x.first == dst){
                        //     return price[x.first];
                        // }
                    }
                }
              
            }
            i++;
        }
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends