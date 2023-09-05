//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
    long long helper(int coins[], int sum, int i, vector<vector<long long>> &dp){
        if(i <0){
            if(sum   == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        long long notTake = helper(coins, sum , i-1, dp);
        long long take = 0;
        if(sum >= coins[i])
         take = helper(coins, sum-coins[i] , i, dp);
        
        return dp[i][sum] = notTake + take;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long long>> dp(N, vector<long long> (sum + 1, -1));
        
        return helper(coins,sum, N-1, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends