//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n = matrix.size();
	  
	    
	        for(int a=0;a<n;a++){
	            for(int b =0;b<n;b++){
	                if(a == b){
	                    matrix[a][b] =0;
	                }
	                else if(matrix[a][b] == -1){
	                    matrix[a][b] = 1e9;
	                }
	            }
	        }
	    for(int i=0;i<n;i++){
	    
	        for(int a=0;a<n;a++){
	            for(int b =0;b<n;b++){
	                matrix[a][b] = min(matrix[a][b] , matrix[a][i] + matrix[i][b]);
	            }
	        }
	      
	    }
	    for(int a=0;a<n;a++){
            for(int b =0;b<n;b++){
                if(matrix[a][b] == 1e9){
                    matrix[a][b] = -1;
                }
            }
        }
	    return;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends