//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    int md = (int)1000000007;
    int helper(int arr[], int n , int sum , vector<vector<int>> &dp, int i){
        
        if(i >= n){
            if(sum == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        int a = 0;
        if(sum - arr[i] >= 0){
            a = helper(arr, n , sum - arr[i], dp, i+1);
        }
        int b = helper(arr, n , sum, dp, i+1);
        
        return dp[i][sum] = (a%md + b%md)%md;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1, vector<int> (sum + 1, -1));
        return helper(arr, n,sum, dp, 0);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends