/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.50%)
 * Total Accepted:    371.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * `
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    int j = 0;
    char flag[256];
    for (int i = 0; i < strsSize; i++)
    {
        if (strs[i][j] == '\0')
            break;
        if (i == 0)
            continue;
        if (strs[i][j] != strs[0][j])
            break;
        if (i == strsSize - 1)
        {
            flag[j++] = strs[i][j];
        }
    }
    char *result = (char *)malloc(sizeof(char) * j);
    for (int i = 0; i < j; i++)
    {
        result[i] = flag[j];
    }
    return result;
}
