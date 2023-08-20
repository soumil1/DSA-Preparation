# Question asked in
# maximize the sum of all elements of all subarrays of A[] (GeeksForGeeks Contest 116 - dated 21 August, 2023)


#User function Template for python3
class Solution:
    def maxSum(self, N, A): 
        #code here
        negatives = 0
        for i in range(N):
            factor = (N-i) * (i+1)
            A[i] *= factor
            if A[i] < 0:
                A[i] = -A[i]
                negatives += 1
        if negatives%2 == 0:
            return sum(A)
        else:
            return sum(A) - 2 * min(A)
