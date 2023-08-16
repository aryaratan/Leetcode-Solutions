//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        if(n <= 2){
            return n==0?1:n;
        }
        vector<long long> dp(n+1 , 0);
        dp[0]  = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        int md = 1000000007;
        for(int i=3;i<=n;i++){
            dp[i] =0;
            for(int j=0;j<i;j++){
                dp[i] =dp[i] +(dp[j]* dp[i-j-1]);
                dp[i] = dp[i]%md;
            }
            
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends