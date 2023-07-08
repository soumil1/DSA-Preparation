class Solution
{
public:
    int reverse(int x)
    {
        int soln = 0;
        while (x != 0)
        {
            int sum = x % 10;
            if ((soln > INT_MAX / 10) || (soln < INT_MIN / 10))
            {
                return 0;
            }
            soln = (soln * 10) + sum;
            x = x / 10;
        }
        x = soln;
        return x;
    }
};