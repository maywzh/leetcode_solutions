/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.69%)
 * Total Accepted:    354.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
int strStr(char *haystack, char *needle)
{
    if (needle[0] == '\0')
        return 0;
    int i = 0, j = -1;
    int *next = (int *)malloc(sizeof(int) * 100000);
    next[0] = -1;
    next[1] = 0;
    int plen = 0;
    while (needle[i] != '\0')
        if (j == -1 || needle[i] == needle[j]) //j==-1 对应特殊情况 前后无匹配子串
        {
            ++i, ++j;
            if (needle[i] != needle[j])
                next[i] = j;
            else
                next[i] = next[j];
        }
        else
            j = next[j];
    plen = i;
    i = j = 0;
    while (haystack[i] != '\0' && j < plen)
    {
        if (j == -1 || haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j >= plen)
        return i - plen;
    else
        return -1;
}