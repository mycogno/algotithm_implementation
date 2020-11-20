#include <cstdio>
#include <algorithm>

using namespace std;

int P[100][100];

int fractionalKnapsack(int n, int p[], int w[], int max)
{
    int max_profit = 0;
    int i;
    double ratio[n];
    int cap = max;
    for (i = 0; i < n; i++)
    {
        if (w[i] > cap)
            break;
        ratio[i] = 1.0;
        cap = cap - w[i];
        max_profit = max_profit + p[i];
    }
    if (i <= n)
    {
        ratio[i] = (double)cap / w[i];
        max_profit = max_profit + p[i] * ratio[i];
    }

    return max_profit;
}

int zerooneKnapsack(int n, int p[], int w[], int mx)
{
    if (!n || !mx)
        return 0;
    if (w[n] > mx)
    {
        return zerooneKnapsack(n - 1, p, w, mx);
    }
    return max(zerooneKnapsack(n - 1, p, w, mx), zerooneKnapsack(n - 1, p, w, mx - w[n]) + p[n]);
}

int main()
{
    int X;
    int p[3] = {50, 140, 60};
    int w[3] = {5, 20, 10};
    scanf("%d", &X);
    printf("%d\n", fractionalKnapsack(3, p, w, X));
    printf("%d\n", zerooneKnapsack(3, p, w, X));
    return 0;
}

/*
input : 30
output
220
200
*/