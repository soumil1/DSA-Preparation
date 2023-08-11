// Question asked in Amazon Microsoft Paytm OYO Rooms Samsung BankBazaar
// Finde length of longest increasing subsequence from the given array (GeeksForGeeks POTD - dated 12 August, 2023)

//User function Template for javascript

/**
 * @param {number} n
 * @param {number[]} a
 * @returns {number}
*/


class Solution 
{
    //Function to find length of longest increasing subsequence.
    longestSubsequence(n, a)
    {
        // code here
        let temp = [a[0]];
        for (let i = 1; i < n; i++) {
            if (a[i] > temp[temp.length - 1]) {
                temp.push(a[i]);
            } else {
                let index = this.lowerBound(temp, a[i]);
                temp[index] = a[i];
            }
        }
        return temp.length;
    }
    
    lowerBound(arr, target) {
        let left = 0;
        let right = arr.length;
        while (left < right) {
            let mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}

