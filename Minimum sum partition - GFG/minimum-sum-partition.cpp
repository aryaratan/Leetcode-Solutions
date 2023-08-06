//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int helper(int arr[],int n , int i , int cs, int k , int &ans, vector<vector<int>> &dp ){
        
        
        if(i >= n){
            // cout << k << " " << 2*cs << endl;
            ans = min(abs(k - 2*cs) , ans);
            return ans;
        }
        
        if(dp[i][cs] != -1){
            return dp[i][cs];
        }
        int a = helper(arr,n, i+1, cs+arr[i],k,ans, dp );
    
        int b = helper(arr,n, i+1, cs, k , ans, dp);
        dp[i][cs] = min(a, b);
        return dp[i][cs];
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s = 0;
	    for(int i=0;i<n;i++){
	        s += arr[i];
	    }
	   // int k = s/2;
	    vector<vector<int>> dp(n+1, vector<int> (s+1, -1));
	    int ans = INT_MAX;
	    helper(arr,n, 0, 0,s,ans, dp);
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends