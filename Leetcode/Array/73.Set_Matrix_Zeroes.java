class Solution {
    public void setZeroes(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        for (int i = 0; i < m; i++) { 
		for (int j = 0; j < n; j++) { 
			if (matrix[i][j]==0){
                for (int a = 0; a < m; a++) { 
		        for (int b = 0; b < n; b++) {
                    if(matrix[i][b]==0){
                        matrix[i][b]=0;
                    }else{
                    matrix[i][b]=-10;}
                    if(matrix[a][j]==0){
                        matrix[a][j]=0;
                    }else{
                    matrix[a][j]=-10;}
                }
                }
            }
            continue;
		}
	    }
        for (int i = 0; i < m; i++) { 
		for (int j = 0; j < n; j++) { 
            if (matrix[i][j]==-10){
                 matrix[i][j]=0;}
        }
        }
    }
}