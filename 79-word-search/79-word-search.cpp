class Solution {
public:
    bool check(vector<vector<char>>& board,string word,int row,int col,int idx){
        if(idx==word.size()){
            return true;
        }
        if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col]=='.'||board[row][col]!=word[idx]){
            return false;
        }
        char ch = board[row][col];
        board[row][col] = '.';
        bool ans = false;
            if(check(board,word,row+1,col,idx+1)) ans = true;
            else if(check(board,word,row,col+1,idx+1)) ans = true;
            else if(check(board,word,row-1,col,idx+1)) ans = true;
            else if(check(board,word,row,col-1,idx+1)) ans = true;
        board[row][col] = ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
         for(int i = 0; i<board.size(); i++){
           for(int j=0; j<board[0].size(); j++) { 
              if(check(board,word,i,j,0)){
                  return true;
              }
           }
         }
        return false;
     }
};