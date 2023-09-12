//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N == 1) return 0;
        
        long long i =2, sum =1;
    
        while(i*i <= N ){
            if(N%i == 0) {sum += i; sum += (N/i);}
            i++;
        }
        // cout << sum << endl;
        return sum == N;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends