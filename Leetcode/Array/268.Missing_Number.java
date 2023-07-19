class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int expected = n * (n + 1) / 2;
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return expected - total;
    }

    public static void main(String[] args) {
        int a[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
        Solution solution = new Solution();
        int missing = solution.missingNumber(a);
        System.out.println("Missing number: " + missing);
    }
}