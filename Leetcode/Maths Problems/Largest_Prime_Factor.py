# Question asked in Yahoo
# Find the Largest Prime Factor of a number (GeeksForGeeks POTD - dated 09 August, 2023)

#User function Template for python3

from math import sqrt


class Solution:
    def largestPrimeFactor(self, N):
        prime = -1
        # Even numbers
        while N % 2 == 0:
            prime = 2
            N //= 2

        # Odd numbers
        for i in range(3, int(sqrt(N)) + 1, 2):
            while N % i == 0:
                prime = i
                N //= i

        if N > 2:
            prime = N

        return int(prime)
