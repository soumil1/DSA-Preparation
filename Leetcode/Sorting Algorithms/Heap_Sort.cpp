// Question asked in Amazon Microsoft Samsung 24*7 Innovation Labs Oracle Visa Intuit SAP Labs Belzabar
// Find Heap Sort by completing functions heapify() and buildHeap (GeeksForGeeks POTD - dated 27 July, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

// the function should be written in a way that array become sorted in increasing order when heapSort() is called.

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[large] < arr[left])
            large = left;
        if (right < n && arr[large] < arr[right])
            large = right;
        if (large != i)
        {
            swap(arr[large], arr[i]);
            heapify(arr, n, large);
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        for (int i = n / 2; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // code here
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};