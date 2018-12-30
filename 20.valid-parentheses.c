/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.34%)
 * Total Accepted:    468.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
bool isValid(char *s)
{
    char *stack = (char *)malloc(10000 * sizeof(char));
    bool valid = false;
    int top = -1;
    while (*s != '\0')
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            stack[++top] = *s;
        }
        else if (*s == ')')
        {
            if (stack[top] == '(')
                top--;
            else
                return false;
        }
        else if (*s == ']')
        {
            if (stack[top] == '[')
                top--;
            else
                return false;
        }
        else if (*s == '}')
        {
            if (stack[top] == '{')
                top--;
            else
                return false;
        }
        s++;
    }
    return top < 0;
}
