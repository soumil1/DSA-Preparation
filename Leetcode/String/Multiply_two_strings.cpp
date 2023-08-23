// Question asked in Flipkart Amazon Microsoft Samsung Adobe Google Facebook
// Take two strings as input and returns their product as a string (GeeksForGeeks POTD - dated 24 August, 2023)

// Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// Driver Code Ends

class Solution
{
public:
    string multiplyStrings(string a, string b)
    {
        if (a == "0" || b == "0")
            return "0";

        bool neg = false;
        int lengthA = a.length();
        int lengthB = b.length();

        if (a[0] == '-' && b[0] == '-')
        {
            a = a.substr(1);
            lengthA -= 1;
            b = b.substr(1);
            lengthB -= 1;
        }
        else if (a[0] == '-')
        {
            a = a.substr(1);
            lengthA -= 1;
            neg = true;
        }
        else if (b[0] == '-')
        {
            b = b.substr(1);
            lengthB -= 1;
            neg = true;
        }

        int length = lengthA + lengthB;
        vector<int> result(length, 0);
        int carry = 0;

        for (int i = 0; i < lengthB; i++)
        {
            int x = b[lengthB - 1 - i] - '0';
            for (int j = 0; j < lengthA; j++)
            {
                int y = a[lengthA - 1 - j] - '0';
                result[length - 1 - i - j] += x * y + carry;
                carry = result[length - 1 - i - j] / 10;
                result[length - 1 - i - j] %= 10;
            }
            if (carry != 0)
            {
                result[length - 1 - i - lengthA] = carry;
                carry = 0;
            }
        }

        string output;
        if (neg)
            output += "-";
        bool flag = false;

        for (int i = 0; i < length; i++)
        {
            if (result[i] != 0 || flag)
            {
                output += to_string(result[i]);
                flag = true;
            }
        }

        return output;
    }
};