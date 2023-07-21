//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
typedef  node ListNode;
class Solution
{
    public:
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            // curr = prev -> next;

        }
        return prev;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        ListNode* newHead = NULL, *newTail = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            int i = 0;
            ListNode* tempHead= NULL, *tempTail = NULL;

            while(i < k && temp != NULL){
                if(tempHead == NULL){
                    tempHead = tempTail = temp;
                }
                else{
                    tempTail -> next = temp;
                    tempTail = tempTail -> next;
                }
                temp = temp -> next;
                i++;
            }

            tempTail -> next = NULL;
            // if(i == k){
                ListNode* rev = reverse(tempHead);
                if(newHead == NULL){
                    newHead =  rev;
                    newTail = tempHead;
                }
                else{
                    newTail -> next = rev;
                    newTail = tempHead;
                }
            // }
            // else{
                
            //     if(newHead == NULL){
            //         newHead =  tempHead;
            //     }
            //     else{
            //         newTail -> next = tempHead;
            //         newTail = tempTail;
            //     }
            // }

        }
        return newHead;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends