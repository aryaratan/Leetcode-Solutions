//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool helper(long mid, long N ,long M, long L, long H[], long A[] ){
        long ts = 0;
        for(long i =0;i<N;i++){
            long ns = H[i] + A[i]*mid;
            if(ns >= L){
                ts += ns;
            }
        }
        return ts >= M;
    }

    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long  a = 0, b = INT_MAX;
        while( a <= b){
            long mid = a - (a-b) / 2;
            
            bool flag = helper(mid,N, M, L,H, A);
            
            if(flag){
                b = mid-1;
            }
            else{
                a = mid +1;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends