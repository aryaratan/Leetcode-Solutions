//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    vector<int> parents;
    vector<int> sizes;
    
    int ultPar(int u){
        if(u == parents[u]){
            return u;
        }
        
        return parents[u] = ultPar(parents[u]);
    }
    
    void connect(int u, int v){
        int up = ultPar(u);
        int vp = ultPar(v);
        
        if(up == vp){
            return;
        }
        if(sizes[up] < sizes[vp]){
            parents[up] = vp;
            sizes[vp] += sizes[up];
            sizes[up] = 1;
        }
        
        else{
            parents[vp] = up;
            sizes[up] += sizes[vp];
            sizes[vp] = 1;
        }
        
    }
  
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        
        parents.resize(n);
        sizes.resize(n, 1);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    connect(i , j);
                }
            }
        }
        int  mx =0;
        
        set<int> compo;
        for(int i=0;i<n;i++){
            
            mx += (sizes[i] - 1);
        }
        
        return mx ;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends