//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    

    vector<vector<string>> findSequences(string beginWord, string targetWord, vector<string>& wordList) {
        // code here
        queue<vector<string>> q;
        vector<string> start = {beginWord};
        q.push(start);
        set<string> str(wordList.begin(), wordList.end());
        str.erase(beginWord);
        if(str.find(targetWord) == str.end()){
            vector<vector<string>> ans;
            // cout << "back" << endl;
            return ans;
        }
        vector<vector<string>> ans;
        while(!q.empty()){
            
            int s = q.size();
            while(s--){
                vector<string> t = q.front();
                q.pop();
                
                string last = t.back();
                // cout << last << endl;
                str.erase(last);
                for(int j=0;j<last.length();j++){
                    string word = last;
                    for(int i=0;i<26;i++){
                        // char c = last[j];
                        word[j] = 'a' + i;
                        
                        // cout << word << " ";
                        if(word == targetWord){
                            t.push_back(word);
                            ans.push_back(t);
                            t.pop_back();
                        }
                        if(str.find(word) != str.end()){
                            
                            t.push_back(word);
                            q.push(t);
                            t.pop_back();
                        }
                        
                    }
                    // cout << endl;
                }
                
            }
            if(ans.size() != 0){
                // for(auto i:ans){
                //     for(auto a:i){
                //         cout << a << " ";
                //     }
                //     cout << endl;
                // }
                return ans;
            }
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends