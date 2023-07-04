//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
// 	#define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll ans = 0;
	    
	    ll l = 0,r =0;
	    
	   // 3 2 1
	   // ans = 0, l = 0 , r = 1;
	    
	   // r = 3
	   // e = 6
	    
	    while(r < n){
	        bool f = false;
	        while(r < n && arr[r] <= k){
	            f = true;
	            r++;
	        }
	        
	        ll e = (ll)r - (ll)l ;
	        if(e > 0 && f)
	            ans += e * (e+1)/2;
	        l = ++r;
	       // r++;
	        
	    }
	   ll t = (ll)n*((ll)n+1)/2;
	   return t - ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends