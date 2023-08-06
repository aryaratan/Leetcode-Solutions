//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    void rev(string &s){
        int i=0, j=s.length() -1;
        
        while(i < j){
            swap(s[i], s[j]);
            i++, j--;
        }
        return;
    }
    
    string reverse(string str)
    { 
        //code here.
        string s = "";
        for(int i=0;i<str.length();i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                s.push_back(str[i]);
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                s.push_back(str[i]);
            }
            
        }
        
        rev(s);
        int j =0;
        for(int i=0;i<str.size();i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = s[j++];
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] = s[j++];
            }
        }
        return str;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends