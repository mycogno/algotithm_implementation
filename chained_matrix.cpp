/*
pseudo-code

int minmult(int n, const int d[], index P[][])
{
index i, j, k, diagonal;
int M[1..n, 1..n];
for(i=1; i <= n; i++)
M[i][i] = 0;
for(diagonal = 1;diagonal <= n-1;diagonal++)
for(i=1;i <= n-diagonal;i++) { 
j = i + diagonal;
M[i][j] = minimum (M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]);
i≤k≤j-1
P[i][j] = a value of k that gave the minimum;
}
return M[1][n];
}

void order(index i, index j)
{
if (i == j) cout << “A” << i;
else {
k = P[i][j];
cout << “(”;
order(i,k);
order(k+1,j);
cout << “)”;
}
}
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int P[10][10], M[10][10];

int minmult(int n, int* d){
    int i, j, k, diagonal;

    for(i=1; i<=n; i++)
        M[i][i] = 0;
    for(diagonal=1; diagonal<=n-1; diagonal++){
        for(i=1; i<=n-diagonal; i++){
            j = i + diagonal;
            int min_val = M[i][i]+M[i+1][j]+d[i-1]*d[i]*d[j];
            for(k=i+1; k<=j-1; k++)
                min_val = min(min_val, M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]);
            M[i][j] = min_val;
            for(k=i; k<=j-1; k++){
                if(min_val == M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]){
                    P[i][j] = k;
                    break;
                }
            }
        }
    }
    return M[1][n];
}

void order(int i, int j){
    if(i==j) printf("A%d", i);
    else{
        int k = P[i][j];
        printf("(");
        order(i, k);
        order(k+1, j);
        printf(")");
    }
}

int main(){
    int n, min_val;
    int d[10];
    printf("Enter the value n : ");
    scanf("%d", &n);
    printf("Enter the values from d0 to d%d : ", n);
    for(int i=0; i<=n; i++){
        scanf("%d", &d[i]);
    }
    min_val = minmult(n, d);
    printf("min # of multiplication is %d.\n", min_val);
    printf("result matrix M:\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!M[i][j]) printf("  ");
            else printf("%d", M[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("order : ");
    order(1, n);
    printf("\n");

    return 0;
}
/*
Enter the value n : 6
Enter the values from d0 to d6 : 5 2 3 4 6 7 8
min # of multiplication is 348.
result matrix M:
   30 64 132 226 348
      24 72 156 268
         72 198 366
            168 392
               336

order : (A1((((A2A3)A4)A5)A6))
*/