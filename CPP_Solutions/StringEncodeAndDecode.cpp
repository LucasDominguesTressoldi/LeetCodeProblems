class Solution
{
public:
  string encode(vector<string> &strs)
  {
    string result = "";
    for (const string &s : strs)
      result += to_string(s.length()) + "#" + s;
    return result;
  }

  vector<string> decode(string str)
  {
    vector<string> result;
    int length, i = 0;
    while (i < str.size())
    {
      int j = i;
      while (str[j] != '#')
        ++j;
      length = stoi(str.substr(i, j));
      result.push_back(str.substr(j + 1, length));
      i = j + 1 + length;
    }

    return result;
  }
};
