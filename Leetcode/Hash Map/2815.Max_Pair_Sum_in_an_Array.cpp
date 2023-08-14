class Solution
{
public:
    int getMaxDigit(int num)
    {
        int maxDigit = 0;
        while (num > 0)
        {
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }

    int maxSum(vector<int> &nums)
    {
        unordered_map<int, int> maxDigitToMaxSum;
        int maxSum = -1;

        for (int num : nums)
        {
            int maxDigit = getMaxDigit(num);
            if (maxDigitToMaxSum.count(maxDigit))
            {
                maxSum = max(maxSum, maxDigitToMaxSum[maxDigit] + num);
                maxDigitToMaxSum[maxDigit] = max(maxDigitToMaxSum[maxDigit], num);
            }
            else
            {
                maxDigitToMaxSum[maxDigit] = num;
            }
        }

        return maxSum;
    }
};