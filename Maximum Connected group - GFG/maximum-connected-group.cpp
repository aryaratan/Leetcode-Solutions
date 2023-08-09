//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    vector<int> parents;
    vector<int> sizes;
    
    
    int findPars(int u){
        if(u == parents[u]){
            return u;
        }
        
        return parents[u] = findPars(parents[u]);
    }
    
    
    void unionBySize(int u, int v){
        int up = findPars(u);
        int vp = findPars(v);
        
        if(up == vp){
            return;
        }
        if(sizes[up] < sizes[vp]){
            parents[up] = vp;
            sizes[vp] += sizes[up];
        }
        else{
            parents[vp] = up;
            sizes[up] += sizes[vp];
        }
        
        
        return;
    }
   
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        parents.resize(n*n);
        sizes.resize(n*n);
        
        for(int i=0;i<n*n;i++){
            parents[i] = i;
            sizes[i] = 1;
        }
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int u = i*n + j;
                    
                    int rows[] = {0,1,0,-1};
                    int cols[] = {1,0,-1,0};
                    
                    for(int k=0;k<4;k++){
                        int x = i+rows[k] , y = j+cols[k];
                        
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y] == 1){
                            int v = x*n + y;
                            unionBySize(u, v);
                           
                        }
                    
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j] == 0){
                    int u = i*n + j;
                    
                    int rows[] = {0,1,0,-1};
                    int cols[] = {1,0,-1,0};
                    set<int> par;
                    for(int k=0;k<4;k++){
                        int x = i+rows[k] , y = j+cols[k];
                        
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1){
                            int v = x*n + y;
                            par.insert(findPars(v));
                        }
                    }
                    
                    int curSize = 1;
                    for(auto it:par){
                        curSize += sizes[it];
                        // cout << it << endl;
                    }
                    
                    count = max(count , curSize);
                }
            }
        }
        
        for(int i=0;i<n*n;i++){
            int x = findPars(i);
            count = max(count , sizes[x]);
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends