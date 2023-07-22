class Solution {
    public int maxSubArray(int[] numbers) {

        // maximum sum possible
        int maximum_far = numbers[0];

        // store the maximum found at the position
        int current_max = numbers[0];

        for(int j = 1; j < numbers.length; j++) {
            // Equivalent to step 3
            current_max = Math.max(numbers[j], numbers[j] + current_max);

            // Equivalent to step 4
            maximum_far = Math.max(current_max, maximum_far);
        }
        return maximum_far;
    }
}