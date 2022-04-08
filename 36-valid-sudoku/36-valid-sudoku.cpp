class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int>v(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(v[board[i][j]-'0']>0){
                    return false;
                }
                v[board[i][j]-'0']++;
            }
        }
        for(int j=0;j<9;j++){
            vector<int>v(10,0);
            for(int i=0;i<9;i++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(v[board[i][j]-'0']>0){
                    return false;
                }
                v[board[i][j]-'0']++;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                vector<int>v(10,0);
                for(int x=3*i;x<3*(i+1);x++){
                  for(int y=3*j;y<3*(j+1);y++){
                     if(board[x][y]=='.'){
                       continue;
                     }
                     if(v[board[x][y]-'0']>0){
                       return false;
                     }
                     v[board[x][y]-'0']++;
                   }
                }
             }
         }
        return true;
    }
};