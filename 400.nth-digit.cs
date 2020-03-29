/*
 * @lc app=leetcode id=400 lang=csharp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (29.92%)
 * Total Accepted:    42.5K
 * Total Submissions: 142.2K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
public class Solution
{
    public int FindNthDigit(int n)
    {
        int nums = 9, digits = 1;
        while (n - nums * digits > 0 && nums * digits > 0)
        {
            n -= nums * digits;
            nums *= 10;
            digits++;
        }

        int no = (n - 1) / digits; //第no+1个数
        int d = (n - 1) % digits;  //第d位数
        int mult = nums / 9;
        if (d == 0)
            return no / mult + 1;
        for (int i = 0; i < d; i++)
        {
            no %= mult;
            mult /= 10;
        }
        return no / mult;
    }
}
