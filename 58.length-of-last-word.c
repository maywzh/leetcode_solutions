/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.07%)
 * Total Accepted:    231.1K
 * Total Submissions: 720.5K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
int lengthOfLastWord(char *s)
{
    int i = 0, len = 0;
    int head = 0, rear = 0;
    while (s[i] != '\0')
        i++;
    --i;
    while (s[i] == ' ')
        i--;
    while (i >= 0 && s[i] != ' ')
    {
        len++;
        i--;
    }

    return len;
}