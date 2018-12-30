/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (38.68%)
 * Total Accepted:    241.5K
 * Total Submissions: 624.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
char *countAndSay(int n)
{
    char *result = (char *)malloc(sizeof(char) * 10000);
    char *tmp = (char *)malloc(sizeof(char) * 10000);
    char *p;

    char c = ' ';
    int i, j, k, w;
    result[0] = '1';
    result[1] = '\0';
    for (i = 2; i <= n; i++)
    {
        j = k = 1;
        w = 0;
        c = result[0];
        while (result[j] != '\0')
        {
            if (result[j] == c)
                k++;
            else
            {
                tmp[w++] = k + '0';
                tmp[w++] = c;
                c = result[j];
                k = 1;
            }
            j++;
        }
        tmp[w++] = k + '0';
        tmp[w++] = c;
        tmp[w] = '\0';
        j = 0;
        while (tmp[j] != '\0')
        {
            result[j] = tmp[j];
            j++;
        }
        result[j] = '\0';
    }
    return result;
}
