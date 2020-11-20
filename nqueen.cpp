#include <cstdio>
#include <cstdlib>
using namespace std;
/*
col(i) : i째 행에서 여왕말이 놓여있는 열
col(i) = col(k) 이면, i째 행과 k째 행에 놓여있는 여왕말은
같은 열에 놓여 있다.
abs(col(i) - col(k)) = abs(i-k) 이면, i째 행과 k째 행에 놓여있는
여왕 말은 같은 대각선상에 놓여 있다.
*/

int col[31], count = 0;

void printCase(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("<%d, %d>\n", i, col[i]);
    }
    printf("----------\n");
}

bool promising(int i)
{
    int k = 1;
    bool toggle = true;
    while (k < i && toggle)
    {
        if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
            toggle = false;
        k++;
    }
    return toggle;
}

void queens(int i, const int n)
{
    int j;
    if (promising(i))
    {
        if (i == n)
        {
            // printCase(i);
            count++;
        }
        else
        {
            for (j = 1; j <= n; j++)
            {
                col[i + 1] = j;
                queens(i + 1, n);
            }
        }
    }
}

void improvedQueens(int i, const int n)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        col[i + 1] = j;
        if (promising(i + 1))
        {
            if (i + 1 == n)
            {
                count++;
                // printCase(i + 1);
            }
            else
            {
                improvedQueens(i + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("----------\n");
    // queens(0, n);
    improvedQueens(0, n);
    printf("%d\n", count);
}