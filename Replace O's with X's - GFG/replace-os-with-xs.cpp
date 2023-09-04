//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void bfs(vector<vector<char>> &mat, int n, int m , int i , int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int rows[4] = {0,1,-1,0};
        int cols[4] = {1,0,0,-1};
        mat[i][j] = 'Y';
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int a = x+rows[i];
                int b = y+cols[i];
                
                if(a>=0 && b>=0 && a<n && b<m && mat[a][b] == 'O'){
                    mat[a][b] = 'Y';
                    q.push({a,b});
                }
            }
        }
        return ;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        // boundary se start kro then sabhi O ko kisi new char m change  krr do
        // for all columns 
        for(int i=0;i<m;i++){
            // first row
            if(mat[0][i] == 'O'){
                bfs(mat, n, m , 0,i);
            }
            // last row
            if(mat[n-1][i] == 'O'){
                bfs(mat, n, m , n-1,i);
            }
        }
        // for all rows 
        for(int i=0;i<n;i++){
            // first col
            if(mat[i][0] == 'O'){
                bfs(mat, n, m , i,0);
            }
            // last row
            if(mat[i][m-1] == 'O'){
                bfs(mat, n, m , i,m-1);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
                if(mat[i][j] == 'Y'){
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends