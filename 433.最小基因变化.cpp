/*
 * @lc app=leetcode.cn id=433 lang=cpp
 * @lcpr version=20002
 *
 * [433] 最小基因变化
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) {
            return -1;
        }
        vector<char> AGCT = {'A', 'G', 'C', 'T'};

        // BFS 标准框架
        queue<string> q;
        unordered_set<string> visited;
        q.push(startGene);
        visited.insert(startGene);
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                string cur = q.front();
                q.pop();
                if (cur == endGene) {
                    return step;
                }
                // 向周围扩散
                for (const string &newGene : getAllMutations(cur)) {
                    if (!visited.count(newGene) && bankSet.count(newGene)) {
                        q.push(newGene);
                        visited.insert(newGene);
                    }
                }
            }
            step++;
        }
        return -1;
    }

private:
    vector<string> getAllMutations(const string &gene) {
        vector<string> res;
        string geneChars = gene;
        for (int i = 0; i < geneChars.length(); i++) {
            char oldChar = geneChars[i];
            for (char newChar : vector<char>{'A', 'G', 'C', 'T'}) {
                if (newChar != oldChar) {
                    geneChars[i] = newChar;
                    res.push_back(geneChars);
                }
            }
            geneChars[i] = oldChar;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AACCGGTT"\n"AAACGGTA"\n["AACCGGTA","AACCGCTA","AAACGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AAAAACCC"\n"AACCCCCC"\n["AAAACCCC","AAACCCCC","AACCCCCC"]\n
// @lcpr case=end

 */
