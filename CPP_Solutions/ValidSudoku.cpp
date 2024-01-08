class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    unordered_map<int, int> cols;
    unordered_map<int, int> rows;
    unordered_map<pair<int, int>, int> squares;

    for (int r = 0; r < 9; ++r)
    {
      for (int c = 0; c < 9; ++c)
      {
        if (board[r][c] == ".")
        {
          continue;
        }
        if (rows[r].contains(board[r][c]) || cols[c].contains(board[r][c]) || squares[make_pair((int)r / 3, (int)c / 3)].contains(board[r][c]))
        {
          return false;
        }
      }
      cols[c].insert(board[r][c]);
      rows[c].insert(board[r][c]);
      squares[make_pair((int)r / 3, (int)c / 3)].insert(board[r][c]);
    }
    return true;
  }
};