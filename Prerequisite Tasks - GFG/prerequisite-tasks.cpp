//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int c, vector<int> adj[], bool vis[], bool path[]){
        vis[c] = true;
        path[c] = true;
        
        for(auto x:adj[c]){
            if(!vis[x]){
                if(!dfs(x,adj,vis,path)){
                    return false;
                }
                
            }
            else if(path[x]){
                return false;
            }
        }
        path[c] = false;
        return true;
    }

	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    // detect cycle in Directed graph
	    // return false if cycle else true
	    
	    
	    vector<int> adj[N];
	    
	    for(int i=0;i<P;i++){
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    
	    
	    bool vis[N]={false} , path[N]={false};
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(!dfs(i,adj,vis,path)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends