class Solution
{
public:
    int bestClosingTime(const std::string &customers)
    {
        int penalty = 0;
        int global_penalty = 0;
        int close_index = 0;

        for (int i = 0; i < customers.length(); ++i)
        {
            if (customers[i] == 'Y')
            {
                --penalty;
                if (global_penalty > penalty)
                {
                    global_penalty = penalty;
                    close_index = i + 1; // Convert 0-based index to 1-based index
                }
            }
            else
            {
                ++penalty;
                if (global_penalty > penalty)
                {
                    global_penalty = penalty;
                    close_index = i + 1; // Convert 0-based index to 1-based index
                }
            }
        }

        return close_index;
    }
};
