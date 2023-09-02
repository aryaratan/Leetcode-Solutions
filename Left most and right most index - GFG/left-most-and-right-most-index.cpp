//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long>V, long long x)
    {
        // code here
        long long l = 0, r =V.size() -1, md;

        while(l <= r){
             md = l - (l- r)/2;
            
            if(V[md] == x){
                break;
            }
            else if(V[md] > x){
                r = md -1;
            }
            else{
                l = md + 1;
            }
        }
        if(V[md] != x){
            return {-1, -1};
            
        }
        
        l = md;
        while(l >= 0 && V[l] == x){
            l--;
        }
        r = md;
        while(r< V.size() && V[r] == x){
            r++;
        }
        
        return {l+1, r-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends