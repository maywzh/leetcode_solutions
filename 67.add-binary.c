/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

char *addBinary(char *a, char *b)
{
    int lena = 0, lenb = 0;
    char *p = a;
    while (*p != NULL)
    {
        lena += 1;
        p++;
    }
    p = b;
    while (*p != NULL)
    {
        lenb += 1;
        p++;
    }
    int lenr = lena > lenb ? lena : lenb;
    
}
