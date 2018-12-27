/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.77%)
 * Total Accepted:    550.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
int reverse(int x)
{
    int result = 0;
    int maxint = (1 << 30) - 1 + (1 << 30);
    int minint = (1 << 31);
    if (x == minint)
        return 0;
    int flag = x > 0 ? 1 : -1;
    x *= flag;

    while (x != 0)
    {
        if (result <= maxint / 10)
            result = result * 10 + x % 10;
        else
            return 0;
        x /= 10;
    }
    return result * flag;
}
