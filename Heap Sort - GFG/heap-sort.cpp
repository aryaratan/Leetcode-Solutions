//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int nums[], int n)
    {
        //code here
        for(int i=1;i<n;i++){
        int childIndex = i;
        int parentIndex ;

        while(childIndex>0){
            parentIndex = (childIndex-1)/2;
            if(nums[childIndex] < nums[parentIndex]){
                int temp = nums[parentIndex];
                nums[parentIndex] = nums[childIndex];
                nums[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
            
        }
    }

    //down heapyfy 

    int size = n;
    while(size>1){
       
        int ans = nums[0];
        nums[0] = nums[size-1];
        nums[size-1] = ans;
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex +1;
        int rightChildIndex = 2*parentIndex + 2;
        size--;
        while(leftChildIndex <size){
            int minIndex = parentIndex;
            if(nums[minIndex] > nums[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && nums[rightChildIndex] < nums[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = nums[minIndex];
            nums[minIndex] = nums[parentIndex];
            nums[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex +1;
            rightChildIndex = 2*parentIndex + 2;
        }
        
    }
    reverse(nums, nums + n);
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends