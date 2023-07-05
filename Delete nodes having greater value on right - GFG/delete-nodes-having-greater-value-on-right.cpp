//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        vector<int> vp;
        Node* temp = head;
        while(temp != NULL){
            vp.push_back(temp -> data);
            temp = temp -> next;
        }
        int n = vp.size();
        vector<int> right(n, -1);
        stack<int> st;
        st.push(n - 1);
        for(int i=n - 2 ; i>= 0 ; i--){
            while(!st.empty() && vp[i] >= vp[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }
        
        Node* newHead = NULL , *tail = NULL;
        for(int i=0;i<n;i++){
            if(right[i] == -1){
                if(newHead == NULL){
                    newHead = tail = new Node(vp[i]);
                    
                }
                
                else{
                    tail -> next = new Node(vp[i]);
                    tail = tail -> next;
                }
            }else{
                
            }
        }
        return newHead;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends