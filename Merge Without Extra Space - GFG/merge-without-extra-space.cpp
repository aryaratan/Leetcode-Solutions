//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int gap = (m+n+1)/2;
            
            while(gap >= 1){
                int i = 0, j = gap+i;
                
                while(j<n){
                    if(arr1[i] > arr1[j]){
                        swap(arr1[i], arr1[j]);
                    }
                    i++, j++;
                }
                j -= n;
                while(i < n && j < m){
                    if(arr1[i] >= arr2[j]){
                        swap(arr1[i], arr2[j]);
                    }
                    i++, j++;
                }
                
                
                i  =0;
                while(j < m){
                    if(arr2[i] >= arr2[j]){
                        swap(arr2[i], arr2[j]);
                    }
                    i++, j++;
                }
                
                if(gap == 1){
                    break;
                }
                if(j == m){
                    gap++;
                    
                    gap /= 2;
                    continue;
                }
            }
            return;
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends