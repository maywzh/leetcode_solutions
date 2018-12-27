/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.07%)
 * Total Accepted:    421.6K
 * Total Submissions: 1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
int maxSubArray(int* nums, int numsSize) {
        int maxnum = 1 << 31, sum = 0, maxsum = 1 << 31;
    int hasone = 0;
    for (int i = 0; i < numsSize; i++)
    {
        maxnum = maxnum < nums[i] ? nums[i] : maxnum;
        if (sum + nums[i] < 0)
        {
            sum = 0;
        }
        else
        {
            sum += nums[i];
            maxsum = maxsum < sum ? sum : maxsum;
            hasone = 1;
        }
    }
    maxsum = hasone == 1 ? maxsum : maxnum;
    return maxsum;
}
