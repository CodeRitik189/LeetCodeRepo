class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isvalid(board,i,j,k)){
                           board[i][j] = k+'0';
                           if(solve(board)){return true;}
                        }
                    } 
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& board,int row,int col, int k){
        for(int i=0;i<9;i++){
            if(board[row][i]==(k+'0')||board[i][col]==(k+'0')){
                return false;
            }
        }
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[(3*(row/3))+i][(3*(col/3))+j]==(k+'0')){
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};