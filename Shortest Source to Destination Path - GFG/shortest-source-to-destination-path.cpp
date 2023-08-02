//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<vector<int>> dp;
    int dfs(int N, int M, vector<vector<int>> &A, int X, int Y , int  i, int j, vector<vector<int>> &vis){
        
        if(i<0 || j<0 || i>=N || j>= M || A[i][j] == 0 || vis[i][j] == 1){
            return INT_MAX;
        }
        
        if(i == X && j == Y){
            return 0;
        }
        
        
        
        vis[i][j] = 1;if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int a = dfs(N,M,A,X,Y,i+1,j,vis);
        int b = dfs(N,M,A,X,Y,i-1,j,vis);
        int c = dfs(N,M,A,X,Y,i,j+1,vis);
        int d = dfs(N,M,A,X,Y,i,j-1,vis);
        
        
        int x = min(a,min(b,min(c,d))) ;
        x = x==INT_MAX ? INT_MAX : x+1;
        return dp[i][j] = min(dp[i][j], x);
        
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X == 0 && Y == 0 ){
            if(A[0][0] == 1) return 0;
            
            return -1;
        }
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        vector<vector<int>> vis(N,vector<int>(M,false));
        
        
        queue<pair<pair<int, int>,int>> q;
        q.push({{0,0},0});
        vector<int> rows = {0,1,0,-1};
        vector<int> cols = {1,0,-1,0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r = x + rows[i];
                int c = y + cols[i];
               
                 if(r == X && c == Y && A[r][c] != 1){
                    return -1;
                }
                
                if(r >=0 && c >= 0 && r < N && c < M && A[r][c] == 1 && !vis[r][c]){
                     if(r == X && c == Y){
                    return d + 1;
                }
                    q.push({{r,c},d+1});
                    vis[r][c] = true;
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends