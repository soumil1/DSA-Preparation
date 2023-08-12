class Solution {

    /**
     * @param Integer[][] $obstacleGrid
     * @return Integer
     */
    function uniquePathsWithObstacles($obstacleGrid) {
        $M = count($obstacleGrid);
        $N = count($obstacleGrid[0]);
        $dp = array_fill(0, $N, 0);
        $dp[$N - 1] = 1;

        for($row = $M - 1; $row >= 0; $row--){
            for($col = $N - 1; $col >= 0; $col--){
                if($obstacleGrid[$row][$col]){
                    $dp[$col] = 0;
                }
                else if($col + 1 < $N) {
                    $dp[$col] = $dp[$col] + $dp[$col + 1];
                }
                
            }
        }
        return $dp[0];
    }
}