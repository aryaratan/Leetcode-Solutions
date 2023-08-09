//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    vector<int> parents;
    
    int ultPar(int u){
        if(u == parents[u]){
            return u;
        }
        
        return parents[u] = ultPar(parents[u]);
    }
  
    void unionNode(int u, int v){
        int up = ultPar(u);
        int vp = ultPar(v);
        
        parents[up] = vp;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
        
        // union by merging
        int n = accounts.size();
        parents.resize(n, 0);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        
        
        unordered_map<string , int> mp;

        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                   unionNode(i, mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
        
        unordered_map<int , vector<string>> mp2;
        
        for(auto p:mp){
            int u = p.second;
            string str = p.first;
            
            int par = ultPar(u);
            
            mp2[par].push_back(str);
        }
        int k = mp2.size();
        
        
        vector<vector<string>> ans;
        for(auto x:mp2){
            vector<string> v = x.second;
            sort(v.begin(), v.end());
            
            v.insert(v.begin(), accounts[x.first][0]);
            
            ans.push_back(v);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends