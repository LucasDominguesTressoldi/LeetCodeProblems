class Solution
{
public:
  bool isPalindrome(string str)
  {
    string inverse;

    for (int i = str.length() - 1; i >= 0; --i)
    {
      if (isalnum(str[i]))
      {
        str[i] = tolower(str[i]);
        inverse += str[i];
      }
      else
      {
        str.erase(i, 1);
      }
    }

    return str == inverse;
  }
};