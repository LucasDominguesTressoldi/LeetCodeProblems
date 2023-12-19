class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hashmap;
    int diff{0};

    for (int i{0}; i < nums.size(); i++)
    {
      diff = target - nums[i];
      if (hashmap.find(diff) != hashmap.end())
      {
        return {hashmap[diff], i};
      }
      hashmap[nums[i]] = i;
    }
    return {};
  };
};
