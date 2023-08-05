//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int dt) {
        
        
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));
        
        for(auto e:edges){
            matrix[e[0]][e[1]] = e[2];
            matrix[e[1]][e[0]] = e[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i] =0;
        }
        for(int i=0;i<n;i++){
	        for(int a=0;a<n;a++){
	            for(int b =0;b<n;b++){
	                matrix[a][b] = min(matrix[a][b] , matrix[a][i] + matrix[i][b]);
	            }
	        }
	    }
        
        int ans = 0, minCity = n;
        
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(i != j && matrix[i][j] <= dt){
                    cnt++;
                }
            }
           if(cnt <= minCity){
               minCity = cnt;
                ans = i;
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
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends