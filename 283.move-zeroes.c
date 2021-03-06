/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (53.02%)
 * Total Accepted:    388.2K
 * Total Submissions: 732.1K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
void moveZeroes(int *nums, int numsSize)
{
    int swaped;
    for (int i = numsSize - 1; i >= 1; i--)
    {
        swaped = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] == 0 && nums[j + 1] != 0)
            {
                nums[j] = nums[j + 1];
                nums[j + 1] = 0;
                swaped = 1;
            }
        }
        if (swaped == 0)
            break;
    }
}
