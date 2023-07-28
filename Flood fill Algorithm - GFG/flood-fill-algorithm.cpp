//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        queue<pair<pair<int,int>, int>> q;
        q.push({{sr,sc},image[sr][sc]});
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[sr][sc] = true;
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                pair<pair<int,int>, int> p = q.front();
                int cr = p.first.first;
                int cc = p.first.second;
                int oc = p.second;
                vector<vector<int>> mov = {{0,1},{1,0},{-1,0},{0,-1}};
                
                for(auto x:mov){
                    int nr = cr + x[0];
                    int nc = cc + x[1];
                    
                    if(nr >= 0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]&&image[nr][nc] == oc ){
                        q.push({{nr,nc},oc});
                        vis[nr][nc]=true;
                    }
                }
                image[cr][cc] = newColor;
                q.pop();
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends