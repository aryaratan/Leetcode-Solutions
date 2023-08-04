//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> efforts(n , vector<int>(m ,INT_MAX));
        
        
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        // grid[s.first][s.second] = 0;
        pq.push({0, 0, 0});
        efforts[0][0] = 0;
        
        int rows[4] = {0,1,0,-1};
        int cols[4] = {1,0,-1,0};
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            
            int dis = pq.top()[0];
            
            pq.pop();
            for(int i=0;i<4;i++){
                int r = x + rows[i];
                int c = y + cols[i];
                

                if(r >=0 && r<n && c>=0 && c <m  ){
                    int e = abs(heights[x][y] - heights[r][c]);
                    int ef = max(dis, e);
                    if(efforts[r][c] > ef){
                        efforts[r][c] = ef;
                        pq.push({ef,r,c});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends