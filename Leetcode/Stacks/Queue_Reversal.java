// Question asked in  Amazon
// How to Reverse the Queue (using Stack)[GeeksForGeeks POTD - dated 16 July, 2023]

// Driver Code Starts
import java.util.*;
import java.io.*;

class Reversing{
    // Driver Code Ends
}

// Driver Code Ends

//User function Template for Java
/*Complete the function below*/
class GfG{
    //Function to reverse the queue.
    public Queue<Integer> rev(Queue<Integer> q){
        //add code here.
        Stack<Integer> stack = new Stack<>();
        while (!q.isEmpty()) {
            int x = q.poll();
            stack.push(x);
        }
        while (!stack.isEmpty()) {
            int x = stack.pop();
            q.offer(x);
        }
        return q;
    }
}
