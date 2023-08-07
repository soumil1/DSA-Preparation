class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        // Binary search for the row
        int top = 0;
        int bottom = ROWS - 1;
        while (top <= bottom)
        {
            int row = (top + bottom) / 2;
            if (target > matrix[row][COLS - 1])
            {
                top = row + 1;
            }
            else if (target < matrix[row][0])
            {
                bottom = row - 1;
            }
            else
            {
                break;
            }
        }

        if (!(top <= bottom))
        {
            return false;
        }

        // Binary search for the column in the found row
        int row = (top + bottom) / 2;
        int left = 0;
        int right = COLS - 1;
        while (left <= right)
        {
            int col = (left + right) / 2;
            if (target > matrix[row][col])
            {
                left = col + 1;
            }
            else if (target < matrix[row][col])
            {
                right = col - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};