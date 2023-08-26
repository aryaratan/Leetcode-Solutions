//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rows, cols;
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += matrix[i][j];
            }
            mx = max(mx, sum);
            rows.push_back(sum);
        }
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                sum += matrix[j][i];
            }
            mx = max(mx, sum);
            cols.push_back(sum);
        }
        for(int i=0;i<n;i++){
            rows[i] = mx -rows[i];
            cols[i] = mx - cols[i];
        }
        
        
        int ans = 0;
        for(int i=0;i<n;i++){
            rows[i] = rows[i];
            cols[i] = cols[i];
            // cout << rows[i] << " " << cols[i] << endl;
            int temp = min(rows[i], cols[i]);
            // cout << temp<< endl;
            ans += temp;
            rows[i] -= temp;
            cols[i] -= temp;
            // cout << rows[i] << " " << cols[i] << endl;
            if(i != n-1){
                // cout << rows[i+1] << " " << cols[i+1] << endl;
                rows[i+1] += rows[i];
                cols[i+1] += cols[i];
            }
        }
        
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends