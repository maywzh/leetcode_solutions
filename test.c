#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int addone = 0, tmp;
    struct ListNode *rear;
    struct ListNode *l1head = l1;
    while (l1 != NULL && l2 != NULL)
    {
        tmp = l1->val + l2->val + addone;
        l1->val = tmp % 10;
        addone = tmp / 10;
        rear = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 != NULL)
    {
        while (l1 != NULL)
        {
            if (addone == 0)
                break;
            tmp = l1->val + addone;
            l1->val = tmp % 10;
            addone = tmp / 10;
            rear = l1;
            l1 = l1->next;
        }
    }
    else if (l2 != NULL)
    {
        rear->next = l2;
        while (l2 != NULL)
        {
            if (addone == 0)
                break;
            tmp = l2->val + addone;
            l2->val = tmp % 10;
            addone = tmp / 10;
            rear = l2;
            l2 = l2->next;
        }
    }
    if (addone > 0)
    {
        rear->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        rear->next->val = addone;
        rear->next->next = NULL;
    }
    return l1head;
}
struct ListNode *ToListNode(int *arr, int size)
{
    struct ListNode *head, *p;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    head = p;
    for (int i = 0; i < size; i++)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = arr[i];
        p->next->next = NULL;
        p = p->next;
    }
    return head->next;
}

void printLN(struct ListNode *p)
{
    while (p != NULL)
    {
        printf(p->next != NULL ? "%d -> " : "%d", p->val);
        p = p->next;
    }
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    int j = 0;
    char flag[256];
    for (int i = 0; i < strsSize; i++)
    {
        if (strs[i][j] == '\0')
            break;
        if (i == 0)
            continue;
        if (strs[i][j] != strs[0][j])
            break;
        if (i == strsSize - 1)
        {
            flag[j++] = strs[i][j];
        }
    }
    char *result = (char *)malloc(sizeof(char) * j);
    for (int i = 0; i < j; i++)
    {
        result[i] = flag[j];
    }
    return result;
}

int maxSubArray(int *nums, int numsSize)
{
    int sum = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum = (sum + nums[i]) > 0 ? (sum + nums[i]) : 0;
        max = max < sum ? sum : max;
    }
    return max;
}
int main()
{
    // char *str1 = "sdfadfa";
    // char *str2 = "sdfff";
    // char strs[][7] = {"sdfadfa", "sdfff"};
    // printf("%s", longestCommonPrefix(strs, 2));
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int x = maxSubArray(arr, 9);
    return 0;
}