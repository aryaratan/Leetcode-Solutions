//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int> pars;
    int ultPar(int u){
        if(u == pars[u]){
            return u;
        }
        return pars[u] = ultPar(pars[u]);
    }
  
    int Solve(int V, vector<vector<int>>& edges) {
        // code here
      int countExtra = 0;
        pars.resize(V);
        for(int i=0;i<V;i++){
            pars[i] = i;
        }
        
        for(int i=0;i<edges.size();i++){
           
           int u = ultPar(edges[i][0]);
           int v = ultPar(edges[i][1]);
           
           if(u != v){
               pars[u] = v;
           }
           else{
               countExtra++;
           }
        }
         set<int> st;
        for(int i=0;i<V;i++){
            int u= ultPar(i);
            st.insert(u);
        }
       
        int e =  st.size()-1;
      
        
        if(e > countExtra){
            return -1;
        }
        return e;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends