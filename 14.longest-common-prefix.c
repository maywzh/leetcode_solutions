/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.53%)
 * Total Accepted:    373.6K
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
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    char *result = (char *)malloc(1000 * sizeof(char));
    char flag = '\0';
    for (int j = 0; 1 == 1; j++)
    {
        if (strs[0][j] != '\0')
            flag = strs[0][j];
        else
        {
            result[j] = '\0';
            break;
        }
        for (int i = 1; i < strsSize; i++)
        {
            if (strs[i][j] == '\0')
            {
                result[j] = '\0';
                return result;
            }
            if (strs[i][j] != flag)
            {
                result[j] = '\0';
                return result;
            }
        }
        result[j] = flag;
    }
    return result;
}
