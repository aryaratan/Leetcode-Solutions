//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    
	   
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> vis(n , vector<int> (m , 0));
	    vector<vector<int>> ans(n , vector<int> (m , 0));
	    queue<pair<pair<int, int>, int>> q;
	    int cnt = 0;
	    for(int i=0;i<n;i++){
	       for(int j=0;j<m;j++){
	           if(grid[i][j] == 1){
	               cnt++;
	               vis[i][j] = 1;
	               
	               ans[i][j] = 0;
	               q.push({{i,j}, 0});
	           }
	       }
	    }
	    if(cnt == n*m){
	        return ans;
	    }
	    vector<int> rows = {0,1,0,-1};
	    vector<int> cols = {1,0,-1,0};
	   // vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
	    while(!q.empty()){
	           
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int dis = q.front().second;
	        ans[i][j] = dis;
	        q.pop();
	       
	        
	        for(int a=0;a<4;a++){
	            int x = i+rows[a];
	            int y = j+cols[a];
	            
	            if(x>=0 && x <n && y>=0 && y<m && vis[x][y] != 1){
	                vis[x][y] = 1;
	               // ans[x][y] = dis+1;
	                q.push({{x,y}, dis+1});
	               // cnt++;
	                
	            }
	        }
	       
	       // if(cnt == n*m){
	       //     return ans;
	       // }
	        
	    }
	    return ans;
	    
// 	     int n = grid.size(), m = grid[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false)); // Mark all vertices as unvisited
//     queue<pair<pair<int, int>, int>> q;
//     // int totalOne = 0;
//     vector<vector<int>>soln(n,vector<int>(m,0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == 1)
//             {
//                 visited[i][j] = true;
//                 q.push({{i, j}, 0});
//                 soln[i][j]=0;
//             }
//             // else if (grid[i][j] == 1)
//             //     totalOne++;
//         }
//     }
//     // if (totalOne == 0)
//     //     return 0;
//     int delRow[] = {1, 0, -1, 0};
//     int delCol[] = {0, 1, 0, -1};
//     // int time = 0;
//     while (!q.empty())
//     {
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int dis = q.front().second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int newR = row + delRow[i];
//             int newC = col + delCol[i];
//             if (newR >= 0 && newC >= 0 && newR < n && newC < m && !visited[newR][newC] && grid[newR][newC] == 0)
//             {
//                 visited[newR][newC] = true;
//                 q.push({{newR, newC}, dis + 1});
//                 soln[newR][newC]=dis+1;
//             }
//         }
//     }
//     return soln;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends