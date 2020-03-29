/*
 * @lc app=leetcode id=961 lang=c
 *
 * [961] N-Repeated Element in Size 2N Array
 *
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (74.59%)
 * Total Accepted:    5.9K
 * Total Submissions: 7.9K
 * Testcase Example:  '[1,2,3,3]'
 *
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of
 * these elements is repeated N times.
 * 
 * Return the element repeated N times.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,3]
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,1,2,5,3,2]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [5,1,5,2,5,3,5,4]
 * Output: 5
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length is even
 * 
 * 
 * 
 * 
 * 
 */
int repeatedNTimes(int *A, int ASize)
{
    int main_num = A[0];
    int times = 1;
    for (int i = 1; i < ASize; i++)
    {
        if (A[i] == main_num)
        {
            times++;
        }
        else
        {
            times--;
            if (times <= 0)
            {
                main_num = A[i];
                times = 1;
            }
        }
    }
    return main_num;
}
