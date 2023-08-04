//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n);
        string a = "",  b = "";
        for(int i=0;i<n;i++){
            a.push_back('0' + arr[i]);
            i++;
            if(i < n)
                b.push_back('0' + arr[i]);
        }
        // cout << a << " " << b << endl;
        string ans = "";
        int c = 0;
        int i = a.length() -1, j = b.length()-1;
        while(i>=0 && j >=0){
            int x=a[i] - '0', y = b[j] -'0';
            int s = x + y + c;
             c = s/10;
            s = s%10;
            ans.push_back(s + '0');
            // cout << x << " " << y << " " << c << endl;
            i--, j--;
        }
        
        while( i >=0 ){
             int x=a[i] - '0';
            int s = x+ c;
             c = s/10;
            s = s%10;
            ans.push_back(s + '0');
            i--;
        }
        while( j >=0 ){
             int y = b[j] -'0';
            int s = y+ c;
             c = s/10;
            s = s%10;
            ans.push_back(s + '0');
            j--;
        }
        if(c > 0){
            ans.push_back(c + '0');
        }
        reverse(ans.begin(), ans.end());
        
        
        while(ans[0] == '0' && ans.size() >1){
           ans =  ans.substr(1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends