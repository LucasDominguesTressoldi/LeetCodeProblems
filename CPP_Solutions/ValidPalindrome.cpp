class Solution
{
public:
  bool alphaNum(char c)
  {
    return !(c >= 'a' && c <= 'z' ||
             c >= 'A' && c <= 'Z' ||
             c >= '0' && c <= '9');
  }

  bool isPalindrome(string str)
  {
    int l = 0;
    int r = str.length() - 1;

    while (l < r)
    {
      while (l < r && alphaNum(str[l]))
        ++l;
      while (r > l && alphaNum(str[r]))
        --r;

      if (tolower(str[l]) != tolower(str[r]))
        return false;

      ++l, --r;
    }

    return true;
  }
};