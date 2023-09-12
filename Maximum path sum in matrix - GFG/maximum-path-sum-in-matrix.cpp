//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int helper(int i, int j , vector<vector<int>> &matrix,  vector<vector<int>> &dp){
        
        if(j <0 || j>= matrix[0].size()){
            return -1;
        }
        if(i == matrix.size() -1){
            if(j >=0 && j < matrix[0].size()){
                return matrix[i][j];
            }
        }
        if(dp[i][j] != -1){
            return  dp[i][j];
        }
        
        int left = helper(i+1,j-1,matrix, dp);
        int right = helper(i+1,j+1, matrix, dp);
        int down = helper(i+1, j , matrix, dp);
        
        return dp[i][j] = max(left, max(right, down)) + matrix[i][j];
        
    }

    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int ans = 0;
        
        // for(int i=0;i<matrix[0].size();i++){
        //     vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        //     int k = helper(0,i,matrix, dp);
        //     ans = max(ans, k);
        // }
        
        
        int n = matrix.size(), m = matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j >0 && j < m-1)
                    matrix[i][j] += max({matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1]});
            
                
                else if(j>0)
                    matrix[i][j] += max(matrix[i-1][j-1], matrix[i-1][j]);
                else if(j<m-1)
                     matrix[i][j] += max(matrix[i-1][j+1], matrix[i-1][j]);
            }
        }
        
        for(int i=0;i<m;i++){
            ans = max(ans, matrix[n-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends