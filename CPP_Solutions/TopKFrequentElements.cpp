class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int numsSize = nums.size();
    unordered_map<int, int> count;
    vector<vector<int>> freq(numsSize + 1);

    for (const int &n : nums)
      ++count[n];
    for (const auto &value : count)
      freq[value.second].push_back(value.first);

    vector<int> topK;
    for (int i = numsSize; i > 0; --i)
    {
      for (const int &n : freq[i])
        topK.push_back(n);
      if (topK.size() == k)
        return topK;
    }
    return topK;
  }
};