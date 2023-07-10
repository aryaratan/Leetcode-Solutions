//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        pair<int, int> ans;
        
        int n = matrix.size(), m = matrix[0].size();
        
        int i = 0, j = 0, dir = 1;
        // 1 = right, 2 = down , 3 = left, 4 = up
        while(i >=0 && i < n && j >=0 && j < m){
            if(matrix[i][j] == 0){
                if(dir == 1){
                    j++;
                }
                else if(dir == 2){
                    i++;
                }
                else if(dir == 3){
                    j--;
                }
                else{
                    i--;
                }
            }
            else{
                matrix[i][j] = 0;
                if(dir == 1){
                    i++;
                    dir = 2;
                    // cout << "1" << endl;
                }
                else if(dir == 2){
                    j--;
                    dir = 3;
                    // cout << "2" << endl;
                }
                else if(dir == 3){
                    i--;
                    dir = 4;
                    // cout << "3" << endl;
                }
                else{
                    j++;
                    dir = 1;
                    // cout << "4" << endl;
                }
                // cout << dir << " " << i << " " << j << endl;
            }
        }
        
        if(dir == 1){
            j--;
        }
        else if(dir == 2){
            i--;
        }
        else if(dir == 3){
            j++;
        }
        else{
            i++;
        }
        ans.first = i, ans.second = j;
        return ans;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends