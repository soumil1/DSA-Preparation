class Solution{
    public long MaxScore(int N, int arr[]){
        // Code Here.
        int n= arr.length-1;
        long dp[][]= new long [n+1][n+1];
        for(long []a: dp)
            Arrays.fill(a, -1);
        return solve(0, n, arr, dp);
    }
    public long solve(int f, int b, int []arr, long [][]dp)
    {
        if(b<f) return 0;
        if(dp[f][b]!=-1) return dp[f][b];
        long min= mi(f, b, arr);
        long p1= (long)arr[f]*(long)(b-f+1) + min + solve(f+1, b, arr, dp);
        long p2= (long)arr[b]*(long)(b-f+1) + min + solve(f, b-1, arr, dp);
        return dp[f][b]= Math.max(p1,p2);
    }
    public long mi(int f, int b, int []arr)
    {
        long min=Long.MAX_VALUE;
        for(int i=f; i<=b; i++)
        {
            min=Math.min(min,(long)arr[i]);
        }
        return min;
    }
}