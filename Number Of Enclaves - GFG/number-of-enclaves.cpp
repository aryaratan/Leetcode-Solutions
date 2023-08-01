//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i<0 || i>=grid.size() || j< 0 || j>= grid[0].size() || grid[i][j] == 0){
            return;
        }
        // vis[i][j] = 1;
        grid[i][j] = 0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n , vector<int>(m , 0));
        
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if(grid[i][m-1] == 1 ){
                dfs(i, m-1,grid);
            }
        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                dfs(0,i,grid);
            }
            if(grid[n-1][i] == 1 ){
                dfs(n-1,i,grid);
            }
        }
        
        int ans =0;
        for(auto x:grid){
            for(auto y:x){
                if(y == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends