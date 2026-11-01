class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int r=0;r<row;r++){
            dfs(r,0,board);
            dfs(r,col-1,board);
        }
        for(int c=0;c<col;c++){
            dfs(0,c,board);
            dfs(row-1,c,board);
        }
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(board[r][c]=='#'){
                    board[r][c] ='O';
                }else if(board[r][c]=='O'){
                    board[r][c]='X';
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]=='X' || board[r][c]=='#')
        return ;
        if(board[r][c]=='O') board[r][c]='#';
        dfs(r+1,c,board);
        dfs(r-1,c,board);
        dfs(r,c+1,board);
        dfs(r,c-1,board);
    }
};
