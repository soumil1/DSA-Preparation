// Question asked in
// Find max and 2nd max from the array, where both of them should be different from each other (GeeksForGeeks DSA to Development - dated 18 Aug, 2023)

class Solution
{
public:
    /* Function to find largest and second largest element
     *sizeOfArray : number of elements in the array
     * arr = input array
     */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = INT_MIN, max2 = INT_MIN;

        /*********************************
         * Your code here
         * This function should return a
         * vector with first element as
         * max and second element as
         * second max
         * *******************************/
        for (int i = 0; i < sizeOfArray; i++)
        {
            if (arr[i] > max)
            {
                max2 = max;
                max = arr[i];
            }
            else if (arr[i] > max2 && arr[i] != max)
            {
                max2 = arr[i];
            }
        }

        vector<int> result;
        result.push_back(max);
        result.push_back((max2 != INT_MIN) ? max2 : -1);
        return result;
    }
};