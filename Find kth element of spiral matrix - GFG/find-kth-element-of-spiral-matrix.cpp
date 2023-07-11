//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		if(k == 1){
 		    return a[0][0];
 		}
//  		if(k > m*n){
//  		    return 0;
//  		}
 		
 		int l=0,r=m-1,t=0,b=n-1;
 		while(l <= r && t<=b){
 		    
 		    for(int i=l;i<=r;i++){
 		        if(k == 1){
 		            return a[t][i];
 		        }
 		     //   cout << a[t][i] << " "<< k << endl;
 		        k--;
 		    }
 		    t++;
 		    for(int i=t;i<=b;i++){
 		        if(k == 1){
 		            return a[i][r];
 		        }
 		     //   cout << a[i][r] << " "<< k << endl;
 		        k--;
 		    }
 		    r--;
 		    for(int i=r;i>=l;i--){
 		        if(k == 1){
 		            return a[b][i];
 		        }
 		     //   cout << a[b][i] << " "<< k << endl;
 		        k--;
 		    }
 		    b--;
 		    for(int i=b;i>=t;i--){
 		        if(k == 1){
 		            return a[i][l];
 		        }
 		     //   cout << a[i][l] << " "<< k << endl;
 		        k--;
 		    }
 		    l++;
 		}
 		
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends