// Question asked in 
// Find no of good sub-arrays in the given array (GeeksForGeeks DSA to Development - dated 18 Aug, 2023)


class Solution
{
public:
    long long solve(int N, vector<int> &A)
    {
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            unordered_set<int> prefixGcds;
            int currentGcd = A[i];

            // Check all subarrays starting from index i
            for (int j = i; j < N; j++)
            {
                currentGcd = gcd(currentGcd, A[j]);
                if (prefixGcds.find(currentGcd) != prefixGcds.end())
                {
                    break; // GCD repeated, no more distinct elements
                }
                prefixGcds.insert(currentGcd);
                count++;
            }
        }

        return count;
    }

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
};