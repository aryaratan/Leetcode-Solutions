//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfsLeft(int i, int j,vector<vector<char>>&grid, string word ){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsLeft(i, j-1, grid, word.substr(1));
    }
    bool dfsRight(int i, int j,vector<vector<char>>&grid, string word ){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0] ){
            return false;
        }
        
        return dfsRight(i, j+1, grid, word.substr(1));
    }
    bool dfsTop(int i, int j,vector<vector<char>>&grid, string word){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsTop(i-1, j, grid, word.substr(1));
    }
    bool dfsDown(int i, int j,vector<vector<char>>&grid, string word){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsDown(i+1, j, grid, word.substr(1));
    }
    bool dfsLeftDown(int i, int j,vector<vector<char>>&grid, string word ){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsLeftDown(i+1, j-1, grid, word.substr(1));
    }
    bool dfsRightDown(int i, int j,vector<vector<char>>&grid, string word){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0] ){
            return false;
        }
        // cout << word[0] << " " << grid[i][j] << endl;
        return dfsRightDown(i+1, j+1, grid, word.substr(1));
    }
    bool dfsRightTop(int i, int j,vector<vector<char>>&grid, string word ){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsRightTop(i-1, j+1, grid, word.substr(1));
    }
    bool dfsLeftTop(int i, int j,vector<vector<char>>&grid, string word ){
        if(word.length() == 0){
            return true;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != word[0]){
            return false;
        }
        
        return dfsLeftTop(i-1, j-1, grid, word.substr(1));
    }
    
    
    bool dfs(int i, int j,vector<vector<char>>&grid, string word){
        
        if(dfsLeft(i, j, grid, word)){
            // cout <<"left " << i << " " << j << endl;
            return true;
        }
        if(dfsRight(i, j, grid, word)){
            // cout <<"rigjt  " << i << " " << j << endl;
            return true;
        }
        if(dfsTop(i, j, grid, word)){
            // cout <<"left " << i << " " << j << endl;
            return true;
        }
        if(dfsDown(i, j, grid, word)){
            return true;
        }
        if(dfsLeftDown(i, j, grid, word)){
            return true;
        }
        if(dfsRightDown(i, j, grid, word)){
            // cout << i << " " << j << endl;
            return true;
        }
        if(dfsRightTop(i, j, grid, word)){
            return true;
        }
        if(dfsLeftTop(i, j, grid, word)){
            return true;
        }
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	   vector<vector<int>> ans ;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(word[0] == grid[i][j]){
	                if(dfs(i,j,grid,word)){
	                    ans.push_back({i, j});
	                }
	            }
	            
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends