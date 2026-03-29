#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> t;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (t.find(target - x) != t.end())
            {
                ans.push_back({target - x, x});
                t[target - x]--;
                if (!t[target - x])
                    t.erase(target - x);
                continue;
            }
            t[x]++;
        }
        return ans;
    }
};