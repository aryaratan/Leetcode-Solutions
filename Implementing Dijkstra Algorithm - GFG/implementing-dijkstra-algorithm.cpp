//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        
        // used for finding shortest cost of path (weighted edges)
        
        vector<int> ans(V, INT_MAX);
        ans[S] = 0;
        
        set<pair<int,int>> st;
        st.insert({0,S});
        while(st.size() >= 1){
          auto it = st.begin();
          int curNode = it -> second;
          int dis = it -> first;
            st.erase(it);
            for(auto v:adj[curNode]){
                int curDis = dis + v[1];
                if(ans[v[0]] == INT_MAX){
                    ans[v[0]] = curDis;
                    st.insert({curDis, v[0]});
                }
                else if(curDis < ans[v[0]]){
                    st.erase({ans[v[0]], v[0]});
                    ans[v[0]] = curDis;
                    st.insert({curDis,v[0]});
                }
            }
        }
        return ans;
        
        
        // // priority queue store distance of node from source in sorted order
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // // distance , node
        // pq.push({0,S});
        
        // while(!pq.empty()){
        //     int d = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
        //     for(auto v:adj[node]){
        //         int cd = d + v[1];
        //         if(cd < ans[v[0]]){
        //             ans[v[0]] = cd;
        //             pq.push({cd,v[0]});
        //         }
        //     }
        // }
        // return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends