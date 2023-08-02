//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    
    string bsf(int V, vector<int> adj[]){
	    vector<int> ans;
	    queue<int> q;
	    vector<int> inDeg(V,0);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            inDeg[adj[i][j]]++;
                
	        }
	    }
	    
	   for(int i=0;i<V;i++){
	       if(inDeg[i] == 0){
	           q.push(i);
	       }
	   }
	    while(!q.empty()){
	        int t = q.front();
	        ans.push_back(t);
	        q.pop();
	        for(auto x:adj[t]){
	            inDeg[x]--;
	            if(inDeg[x] == 0){
	                q.push(x);
	            }
	        }
	    }
	    string s = "";
	    
	    for(auto x:ans){
	      s.push_back('a' + x);
	    }
	    return s;
	}
    
    string findOrder(string dict[], int N, int K) {
        //code here
        
        
        vector<int> adj[K];
        
        for(int i=0;i<N-1;i++){
            string a = dict[i];
            string b = dict[i+1];
            
            int j=0;
            
            while(j<a.length() && j <b.length() && a[j] == b[j]) j++;
            if(j<a.length() && j <b.length())
            adj[a[j] - 'a'].push_back(b[j] - 'a');
        }
        
        
        
        return bsf(K,adj);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends