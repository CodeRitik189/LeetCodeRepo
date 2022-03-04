class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
             if(poured==0){
                 return 0;
             }
         double** dp = new double*[query_row+1];
        for( int i = 0 ; i<=query_row; i++){
            dp[i] = new double[i+1];
            for( int j = 0 ; j<=i; j++){
                dp[i][j]=0;
            }
        }
        double num = double(poured);
        dp[0][0]=poured;
         for( int i = 1 ; i<=query_row; i++){
            for( int j = 0 ; j<= i; j++){
                if(j<i&&dp[i-1][j]>1){
                    dp[i][j]+=(dp[i-1][j]-1)/2;
                }
                if(j>0&&dp[i-1][j-1]>1){
                    dp[i][j]+=(dp[i-1][j-1]-1)/2;
                }
            }
        }
        return min(1.00,dp[query_row][query_glass]);
    }
};