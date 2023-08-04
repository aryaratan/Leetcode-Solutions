//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        
        if(grid[s.first][s.second] == 0 || grid[d.first][d.second] == 0){
         return -1;
        }
        if(s.first == d.first && s.second == d.second ){
            return 0;
        }
        
        
        queue<pair<pair<int, int>, int>> q;
        grid[s.first][s.second] = 0;
        q.push({{s.first, s.second}, 0});
        int rows[4] = {0,1,0,-1};
        int cols[4] = {1,0,-1,0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            
            int dis = q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++){
                int r = x + rows[i];
                int c = y + cols[i];
                
                
                if(r == d.first && c == d.second){
                    return dis + 1;
                }
                if(r >=0 && r<grid.size() && c>=0 && c <grid[0].size() && grid[r][c]){
                    q.push({{r,c},dis+1});
                    grid[r][c] =0;
                }
            }
        }
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends