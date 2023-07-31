class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;

        // using Stack First In First Out method

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;
                if (c == ']' && stack.top() != '[')
                    return false;
                if (c == ')' && stack.top() != '(')
                    return false;
                if (c == '}' && stack.top() != '{')
                    return false;

                stack.pop();
            }
        }

        return stack.empty();
    }
};
