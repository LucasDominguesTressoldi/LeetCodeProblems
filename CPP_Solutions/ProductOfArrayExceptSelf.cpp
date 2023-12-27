class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int numsSize = nums.size();
    int prefix = 1;
    int postfix = 1;
    vector<int> answer(numsSize, 1);

    for (int i = 0; i < numsSize; ++i)
    {
      answer[i] *= prefix;
      prefix *= nums[i];
    }

    for (int i = numsSize - 1; i >= 0; --i)
    {
      answer[i] *= postfix;
      postfix *= nums[i];
    }

    return answer;
  }
};