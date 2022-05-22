class Solution {
public:
    //binary search can also be possible
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int l = 0,r = matrix[0].size()-1;
        // while(r>=0&&l<matrix.size()){
        //     if(matrix[l][r]==target){
        //         return true;
        //     }else if(matrix[l][r]<target){
        //         l++;
        //     }else{
        //         r--;
        //     }
        // }
        // return false;
       int m = matrix.size(),n = matrix[0].size();
       int low = 0, high = m*n-1;
      
       while(low<=high){
           int mid = (high+low)/2;
           if(matrix[mid/n][mid%n] == target){
               return true;
           }else if(matrix[mid/n][mid%n] < target){
               low = mid+1;
           }else{
               high = mid-1;
           }
       }
        return false;
    }
};