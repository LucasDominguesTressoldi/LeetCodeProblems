class Solution
{
public:
  bool isValid(string s)
  {
    vector<char> stack;
    map<char, char> closeToOpen = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for (const char &c : s)
    {
      if (closeToOpen.count(c))
      {
        if (!stack.empty() && stack.back() == closeToOpen[c])
        {
          stack.pop_back();
        }
        else
        {
          return false;
        }
      }
      else
      {
        stack.push_back(c);
      }
    }

    return stack.empty();
  }
};