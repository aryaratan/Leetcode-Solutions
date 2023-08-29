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
    
    private:
    Node* reverse(Node* head){
        Node* prev = NULL, *curr = head;
        while(curr != NULL){
            Node* temp = curr-> next;
            curr -> next = prev;
            prev = curr ;
            curr = temp;
        }
        return prev;
    }
    public:
    
    
    Node *compute(Node *head)
    {
        // your code goes here
        Node* rv = reverse(head);
        // cout << head -> data << " " << rv -> data << endl;
        stack<Node*> st;
        st.push(rv);
        Node* nh = rv;
        // cout << nh -> data << endl;
        rv = rv -> next;
        while(rv != NULL){
            if( rv -> data  >= st.top() -> data){
                st.top() -> next = rv;
                st.push(rv);
            }
            rv = rv -> next;
        }
        st.top() -> next = NULL;
        return reverse(nh);
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