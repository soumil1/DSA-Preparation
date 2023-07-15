class Solution
{
public:
    bool check(vector<int> &numbers)
    {
        // creating a temporary vector
        vector<int> temp;
        int pivot = 0; // pivot element
        for (int j = 0; j < numbers.size() - 1; j++)
        {
            // finding pivot element in the array which is the element after which the array is sorted
            if (numbers[j] > numbers[j + 1])
            {
                pivot = j + 1; 
                break; // breaking the loop after finding the pivot element
            }
        }
        // sorted array created from the pivot element
        for (int j = pivot; j < numbers.size(); j++) 
        {
            temp.push_back(numbers[j]); // pushing the elements in the temporary vector
        }
        for (int j = 0; j < pivot; j++) 
        {
            temp.push_back(numbers[j]); 
        }
        // sorting the two arrays and comparing the two vectors to check if they are equal
        sort(numbers.begin(), numbers.end());
        return temp == numbers; 
    }
};