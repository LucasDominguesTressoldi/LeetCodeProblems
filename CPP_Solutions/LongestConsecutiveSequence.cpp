class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    set<int> numSet(nums.begin(), nums.end());
    int numsSize = nums.size();
    int longest = 0;
    int length;

    for (const int &n : numSet)
    {
      if (numSet.find(n - 1) == numSet.end())
      {
        length = 0;
        while (numSet.find(n + length) != numSet.end())
        {
          ++length;
        }
        longest = max(length, longest);
        if (longest >= numsSize)
          return longest;
      }
    }
    return longest;
  }
};