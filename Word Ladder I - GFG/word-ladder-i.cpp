//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string> st;
        
        queue<pair<string, int>>q;
        q.push({startWord, 1});
        
        while(!q.empty()){
            
            string t = q.front().first;
            int d = q.front().second;
            q.pop();
            // cout << t << " " << d<< endl;
            for(auto s:wordList){
                // string s = x;
                // cout << s << " ";
                int cnt = 0;
                for(int i=0;i<s.length();i++){
                    if(s[i] != t[i] ){
                        cnt++;
                    }
                }
                if(cnt == 1 && st.find(s) == st.end()){
                    // cout << s << " ";
                    if(s == targetWord){
                        return d+1;
                    }
                    q.push({s,d+1});
                    st.insert(s);
                }
            }
            // cout << endl;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends