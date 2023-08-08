//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    int gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}
    
    pair<int, int> simplify(int n , int d){
        int g = gcd(n , d);
        pair<int, int> p = {n/g , d/g};
        return p;
    }
    
    pair<int, int> needed(int n, int d){
        pair<int, int> p = {d- n, d};
        return p;
    }
    
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<string, int> mp;
        
        int ans =0;
        for(int i=0;i<n;i++){
            int x = numerator[i];
            int y = denominator[i];
           
            pair<int, int> si = simplify(x, y);
            pair<int, int> req = needed(si.first, si.second);
            
            string  s = to_string(req.first) + "#" + to_string(req.second);
             string k = to_string(si.first) + "#" + to_string(si.second);
            if(mp.find(s) != mp.end()){
                // cout << k << " " << s<< endl;
                ans += mp[s];
            }
            mp[k]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends