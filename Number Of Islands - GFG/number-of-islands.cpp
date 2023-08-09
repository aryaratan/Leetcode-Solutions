//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    vector<int> parents;
    int ultPar(int u){
        if(u == parents[u]){
            return u;
        }
        
        return parents[u] = ultPar(parents[u]);
    }
    
    bool unionBySize(int u, int v){
        int up = ultPar(u);
        int vp = ultPar(v);
        if(up == vp)
            return false;
            
        parents[up] = vp;
        return true;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        parents.resize(n*m );
        for(int i=0;i<n*m;i++){
            parents[i] = i;
        }
        
        
        vector<int> ans;
        
        vector<vector<int>> matrix(n , vector<int> (m , 0));
        int count =0;
        for(auto x:operators){
            int i = x[0], j = x[1];
            if(i >= n || j>= m || i<0 || j < 0){
                ans.push_back(count);
                continue;
            }
            int u = i*m + j;
            if(matrix[i][j] != 0){
                ans.push_back(count);
                continue;
            }
            count++;
            matrix[i][j] = 1;
            
            if(i-1>=0 && matrix[i-1][j] == 1){
                int v = (i-1)*m + j;
                bool flag = unionBySize(u, v);
                if(flag)
                    count--;
            }
            if(i+1<n && matrix[i+1][j] == 1){
                int v = (i+1)*m + j;
                bool flag = unionBySize(u, v);
                if(flag)
                    count--;
            }
            if(j-1>=0 && matrix[i][j-1] == 1){
                int v = i*m + j-1;
                bool flag = unionBySize(u, v);
                if(flag)
                    count--;
            }
            if(j+1<m && matrix[i][j+1] == 1){
                int v = (i)*m + j+1;
                bool flag = unionBySize(u, v);
                if(flag)
                    count--;
            }
            
            
            
            ans.push_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends