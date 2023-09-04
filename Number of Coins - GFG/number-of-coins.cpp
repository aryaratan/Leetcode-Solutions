//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp;
	int helper(int coins[], int i, int V){
	    if(i == 0){
	        if(V%coins[0] == 0){
	            return V/coins[0];
	        }
	        return 1e9;
	    }
	    if(dp[i][V] != -1){
	        return dp[i][V];
	    }
	    int notTake = helper(coins, i-1, V);
	    int take = INT_MAX;
	    if(V >= coins[i])
	        take = helper(coins, i, V - coins[i])+1;
	       
	   return dp[i][V] = min(notTake, take) ;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    dp.resize(M , vector<int>(V+1, -1));
	    int ans = helper(coins, M-1, V);
	    return dp[M-1][V] >= 1e9?-1:dp[M-1][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends