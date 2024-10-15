#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n = 0;              
    int groupWordCount = 0;  

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char Word[101];  
        int seen[26] = { 0 };  // ���ĺ� �ҹ��� a-z üũ�� ���� �迭
        int isGroupWord = 0; // �׷� �ܾ� ���� �÷��� (0�̸� �׷� �ܾ�, 1�̸� �ƴ�)

        scanf("%s", Word);

        seen[Word[0] - 'a'] = 1; // ù��° ���� ���

        for (int j = 1; Word[j] != '\0'; j++)
        {
            // ���� ���ڿ� ���� ���ڰ� �ٸ���, ���� ���ڰ� �̹� ���Ծ��ٸ� �׷� �ܾ �ƴ�
            if (Word[j] != Word[j - 1] && seen[Word[j] - 'a'] == 1)
            {
                isGroupWord = 1;
                break;
            }
            // ���� ���ڸ� �� ���ڷ� ���
            seen[Word[j] - 'a'] = 1;
        }

        if (isGroupWord == 0)
        {
            groupWordCount++;
        }
    }

    printf("%d\n", groupWordCount);  
    return 0;
}