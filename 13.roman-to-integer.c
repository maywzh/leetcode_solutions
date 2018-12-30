/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (50.68%)
 * Total Accepted:    328.3K
 * Total Submissions: 647.7K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
int romanToInt(char *s)
{
    int i;
    int result = 0, len = 0;
    while (s[len] != '\0')
        len++;
    i = len - 1;
    while (i >= 0 && s[i] == 'I')
    {
        result += 1;
        i--;
    }
    while (i >= 0 && (s[i] == 'V' || s[i] == 'X'))
    {
        result += s[i] == 'V' ? 5 : 10;
        i--;
        while (i >= 0 && s[i] == 'I')
        {
            result -= 1;
            i--;
        }
    }
    while (i >= 0 && (s[i] == 'L' || s[i] == 'C'))
    {
        result += s[i] == 'L' ? 50 : 100;
        i--;
        while (i >= 0 && s[i] == 'X')
        {
            result -= 10;
            i--;
        }
    }
    while (i >= 0 && (s[i] == 'D' || s[i] == 'M'))
    {
        result += s[i] == 'D' ? 500 : 1000;
        i--;
        while (i >= 0 && s[i] == 'C')
        {
            result -= 100;
            i--;
        }
    }
    return result;
}
