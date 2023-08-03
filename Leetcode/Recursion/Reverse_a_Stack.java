// Question asked in
// Reverse the given stack using recursion (GeeksForGeeks POTD - dated 04 August, 2023)

// Driver Code Starts

import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    static void reverse(Stack<Integer> s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            int temp = s.get(i);
            s.set(i, s.get(n - 1 - i));
            s.set(n - 1 - i, temp);
        }
    }
}