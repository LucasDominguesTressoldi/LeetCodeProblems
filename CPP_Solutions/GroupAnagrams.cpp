class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (const string &s : strs)
        {
            vector<int> count(26, 0);

            for (char c : s)
                count[c - 'a']++;

            string mpKey(count.begin(), count.end());

            mp[mpKey].push_back(s);
        }

        for (const pair<string, vector<string>> &value : mp)
            result.push_back(value.second);

        return result;
    }
};