class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            while (left < right && !isAlphaNumeric(s[left]))
            {
                left++;
            }
            while (right > left && !isAlphaNumeric(s[right]))
            {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isAlphaNumeric(char c)
    {
        return (isalpha(c) || isdigit(c));
    }
};