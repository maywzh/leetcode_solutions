/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        sort(candidates.begin(), candidates.end());
        function<void(vector<int>, int, int)> backtrack = [&](vector<int> result_set, int sum, int start) {
            if (sum == target) {
                results.push_back(result_set);
                return;
            }

            for (size_t i = start; i < candidates.size(); i++) {
                int c = candidates[i];
                if (sum + c <= target) {
                    result_set.push_back(c);
                    backtrack(result_set, sum + c, i);
                    result_set.pop_back();
                }
            }
        };

        backtrack({}, 0, 0); // 从空集合开始
        return results;
    }
};
// @lc code=end
