class Solution
{
public:
  string encode(vector<string> &strs)
  {
    string result = "";

    for (const string &word : strs)
    {
      result += to_string(word.length()) + "#" + word;
    }

    return result;
  }

  vector<string> decode(string s)
  {
    if (s == "0#")
    {
      return {""};
    }

    vector<string> result;
    string currStr;
    int strLen;

    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == '#')
      {
        cout << s << endl;
        strLen = s[i - 1] - '0' == 0 ? 10 : s[i - 1] - '0';

        for (int j = i + 1; j <= strLen + i; ++j)
        {
          currStr += s[j];
        }

        result.push_back(currStr);
        currStr = "";
        i += strLen + 1;
      }
    }

    return result;
  }
};
