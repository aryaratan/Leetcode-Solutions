//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end){
            return 0;
        }
        queue<pair<int, int>> q;
        // set<int> st;
        q.push({ start, 0});
        vector<int> st(100000, INT_MAX);
        st[start] = 0;
        while(!q.empty()){
            
            int t = q.front().first;
            int steps = q.front().second;
            q.pop();
            bool flag = true;
            for(int i=0;i<arr.size();i++){
                int ne = arr[i]*t;
                ne = ne % 100000;
                if(ne == end){
                    return steps + 1;
                }
                if(steps + 1 < st[ne]){
                    st[ne] = steps + 1;
                    q.push({ne,steps +1});
                    flag = false;
                }
            }
            // if(flag){
            //     return -1;
            // }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends