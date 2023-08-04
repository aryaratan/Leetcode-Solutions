//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    
    pair<Node*, Node*> reverse(Node* start){
        Node* curr = start;
        Node* prev = NULL;
        while(curr != NULL){
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        pair<Node*, Node*> p = {prev, start};
        return p;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node* start = NULL;
        Node* prev = NULL;
        Node* temp = head;
        int i =1;
        while(i < m && temp != NULL){
            prev = temp;
            temp = temp -> next;
            i++;
        }
        if(prev != NULL){
            prev -> next = NULL;
        }
        start = temp;
        // temp = head;
        // i = 1;
        while(i < n && temp != NULL){
            temp = temp -> next;
            i++;
        }
        
        Node* nxt = temp -> next;
        temp -> next = NULL;
        // cout << "temp " << temp -> data << endl;
        
        pair<Node*, Node*> rev = reverse(start); 
        // cout << rev.first -> data << " " << rev.second-> data << endl;
        if(prev != NULL){
            prev -> next = rev.first;
        }
        else{
            head = rev.first;
        }
        // cout << rev.first  -> data<< endl;
        // Node* r = rev.first;
        // while(r != NULL){
        //     cout << r -> data << endl;
        //     r = r -> next;
        // }
        rev.second -> next = nxt;
        
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends