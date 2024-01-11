class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    using Vector2D = pair<int, int>;
    map<Vector2D, unordered_map<char, int>> squares;

    unordered_map<int, unordered_map<char, int>> cols;
    unordered_map<int, unordered_map<char, int>> rows;

    for (int r = 0; r < 9; ++r)
    {
      for (int c = 0; c < 9; ++c)
      {
        auto currNum = board[r][c];

        if (currNum == '.')
        {
          continue;
        }

        pair<int, int> key = make_pair((int)r / 3, (int)c / 3);
        if (rows[r].find(currNum) != rows[r].end() ||
            cols[c].find(currNum) != cols[c].end() ||
            squares[key].find(currNum) != squares[key].end())
        {
          return false;
        }

        cols[c][currNum] = 1;
        rows[r][currNum] = 1;
        squares[key][currNum] = 1;
      }
    }

    return true;
  }
};