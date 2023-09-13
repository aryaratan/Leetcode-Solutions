//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S == 0){
            if(N == 1) return "0";
            return "-1";
        }
        if( S > 9*N) return "-1";
        string ans = "";
        
        while(N>0){
            if(S>= 9){
                ans.push_back('9');
                S-=9;
                N--;
            }
            else{
                ans.push_back(S + '0');
                N--;
                break;
            }
        }
        while(N--){
            ans.push_back('0');
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends