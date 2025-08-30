class Solution {
public:
    
    // bool validBox(vector<vector<char>>& board , int sr, int er, int sc, int ec){
    //     //3*3
    //     unordered_set<char> st;
    //     for(int i = sr; i<=er; i++){
    //         for(int j = sc; i <=ec; i++){
    //             if(board[i][j]=='.') continue;

    //             if(st.find(board[i][j]) != st.end())
    //             return false;
    //             st.insert(board[i][j]); 
    //         }
    //     }
    //     return true;
    // }
    
    bool isValidSudoku(vector<vector<char>>& board) {
vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num == '.') continue;

            int boxIndex = (i / 3) * 3 + (j / 3);
            if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num))
                return false;

            rows[i].insert(num);
            cols[j].insert(num);
            boxes[boxIndex].insert(num);
        }
    }

    return true;
}
















        // // rows = 9
        // //col = 9

        // //validate rows
        // for(int row = 0; row < 9; row++){
        //     unordered_set<char> st;
        //     for(int col = 0; col < 9; col++){
        //         if(board[row][col] == '.') continue;
                
        //         if(st.find(board[row][col]) != st.end())
        //         return false;
                
        //         st.insert(board[row][col]);
        //     }
        // }

        // //validate the column
        // for(int col = 0; col < 9 ; col++){
        //     unordered_set<char> st;
        //     for(int row = 0; row < 9 ; row++){
        //         if(board[row][col] =='.') continue;
        //         if(st.find(board[row][col]) != st.end())
        //         return false;
        //         st.insert(board[row][col]);

        //     }
        // }

        // // validate the 3*3 boxes
        // for(int sr = 0 ; sr < 9; sr+=3){
        //     int er = sr + 2;
        //     for(int sc = 0; sc < 9 ; sc+=3){
        //         int ec = sc +2;

        //         //sr, sc, er, ec
        //         if(!validBox(board, sr,er,sc,ec))
        //         return false;
        //     }
        // }
        // return true;




    
};