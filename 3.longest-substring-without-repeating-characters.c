/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.79%)
 * Total Accepted:    697.8K
 * Total Submissions: 2.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
int lengthOfLongestSubstring(char *s)
{
    int i, max;
    int *hasht = (int *)malloc(sizeof(int) * 256);
    int *mark = (int *)malloc(sizeof(int) * 100000);
    for (i = 0; i < 256; i++)
    {
        hasht[i] = -1;
    }
    char *p = s;
    i = 1, max = 1; // begin with the 2nd char
    mark[0] = 1;
    hasht[s[0]] = 0;
    while (s[i] != '\0')
    {
        if (hasht[s[i]] < i - mark[i - 1])
        {
            mark[i] = mark[i - 1] + 1;
        }
        else
        {
            mark[i] = i - hasht[s[i]];
        }
        hasht[s[i]] = i;
        max = max < mark[i] ? mark[i] : max;
        i++;
    }
    return max;
}