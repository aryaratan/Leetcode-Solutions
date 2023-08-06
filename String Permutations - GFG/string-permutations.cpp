//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    
    void helper(string &s, int idx, vector<string> &ans){
        if(idx == s.size()-1){
            ans.push_back(s);
            return;
        }
        // ans.push_back(s);
        for(int i=idx;i<s.size();i++){
            swap(s[i], s[idx]);
            helper(s,idx+1,ans);
            swap(s[i], s[idx]);
        }
        
    }
    
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        helper(S,0,ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends