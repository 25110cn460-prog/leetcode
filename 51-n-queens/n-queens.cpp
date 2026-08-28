class Solution {
public:
   bool issafe(vector<string>&board,int r, int c){
    int n= board.size();
    for(int i=0; i<n;i++){
        if(board[r][i]=='Q'){    // horizontal
            return false;
        }
        if(board[i][c]=='Q'){   // vertical
            return false;
        }
    }
    int nr=r;
    int nc=c;
    while(nr>=0 && nc>=0){    // left diagonal
        if(board[nr][nc]=='Q'){
            return false;
        }
        nr--;
        nc--;
    }
    while(r>=0 && c<n ){    // right diagonal
        if(board[r][c]=='Q'){
            return false;
        }
        r--;
        c++;
    }
    return true;

   }
   void chess(vector<string>&board,int r, int c, vector<vector<string>>&ans){
    int n= board.size();
    if(r==n){
        ans.push_back(board);
        return;
    }
    for(int i=c;i<n;i++){
        if(issafe(board,r,i)){
            board[r][i]='Q';
            chess(board,r+1,0,ans);
            board[r][i]='.';
        }
    }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        chess(board,0,0,ans);
        return ans;
        
    }
};