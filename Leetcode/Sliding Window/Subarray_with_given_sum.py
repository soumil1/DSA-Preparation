# Question asked in Amazon Facebook Google Visa
# Find Subarray in the given sum (GeeksForGeeks POTD - )

#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self, arr, n, s):
       #Write your code here
        i = 0
        j = 0
        add = arr[0]
        if s == 0:
            return [-1]
        if s == arr[0]:
           return [1, 1]
        else:
            while (i < n and j < n):
                if add == s:
                    return [i+1, j+1]
                elif add < s:
                    if j+1 < n:
                        j += 1
                        add += arr[j]
                    else:
                        return [-1]

                else:
                    add -= arr[i]
                    i += 1
        return [-1]
