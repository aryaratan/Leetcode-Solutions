#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t ;
	cin >> t;
	while(t--){
	    int n , k;
	    cin >> n >> k;
	    vector<int> arr;
	    for(int i=0;i<n;i++){
	        int d;
	        cin>> d;
	        arr.push_back(d);
	    }
    	
    	
    	priority_queue<int, vector<int> , greater<int> > pq;
    	for(int i=0;i<k;i++){
    	    pq.push(arr[i]);
    	}
    	for(int i=k;i< n;i++){
    	    cout << pq.top() << " ";
    	    pq.pop();
    	    pq.push(arr[i]);
    	}
    	while(!pq.empty()){
    	    cout << pq.top() << " ";
    	    pq.pop();
    	}
    	cout << endl;
	}
	
	return 0;
}