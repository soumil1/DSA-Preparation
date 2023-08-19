class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        if (str2.length() > str1.length())
        {
            return false;
        }
        int p = 0;
        for (int i = 0; i < str1.length() && p < str2.length(); i++)
        {
            if (str1[i] == str2[p])
            {
                p++;
            }
            else if (((str1[i] - 'a') + 1) % 26 + 'a' == str2[p])
            {
                p++;
            }
        }
        return p == str2.length();
    }
};