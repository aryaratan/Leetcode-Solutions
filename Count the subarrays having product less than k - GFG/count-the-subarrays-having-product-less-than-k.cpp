//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
       
        
        long long p = 1;
        int s = 0, e = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            p *= nums[i];
            e++;
            while(s <= e && p >= k){
                if(nums[s] > 0)
                    p /= nums[s];
                s++;
            }
            // cout << p << " ";
            int si = e-s;
            // cout << si << endl;
            if(si > 0)
                ans += (si);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends