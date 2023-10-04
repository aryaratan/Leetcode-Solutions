//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        if(s.length() == 1){
            return mp[s[0]];
        }
        int nums=0;
        int l = s.length();
        for(int i=0;i<s.length();i++){
            if(mp[s[i]] >= mp[s[i+1]]){
                nums += mp[s[i]];
            }else{
                int k = mp[s[i+1]] - mp[s[i]];
                nums += k;  
                i++;
            }
        }
        // if(mp[s[l-2]] >= mp[s[l-1]]){
        //     nums += mp[s[l-1]];
        // }
        return nums;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends