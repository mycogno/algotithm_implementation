#include <cstdio>

/*
pseudo code

void hamiltonian(index j){
    index j;

    if(promising(i))
        if(i == n-1)
            cout << from vindex[0] to vindex[n-1];
        else
            for(j = 2; k <= n; j++){
                vindex[i+1] = j;
                hamiltonian(i+1);
            }
}

bool promising(index i){
    index j;
    bool switch;

    if(i == n-1 &&! W[vindex[n-1]][vindex[0]])
        switch = false;
    else if(i > 0 &&! W[vindex[i-1]][vindex[i]])
        switch = false;
    else{
        switch = true;
        j = 1;
        while(j<i && switch){
            if(vindex[i] == vindex[j])
                switch = false;
            j++;
        }
    }
    return switch;
}
*/

using namespace std;

// W[i][j] i째 정점과 j째 정점이 이어져 있으면 1, 아니면 0
int W[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 1, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 0, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 0, 0, 1, 0}};

// 출발 정점은 1번으로 고정한다.
int vindex[8] = {
    1,
};

bool promising(int i)
{
    int j;
    bool switching;
    // 첫번째와 마지막 정점이 연결되어 있지 않으면 유망하지 않다.
    if (i == 7 && W[vindex[7]][vindex[0]] == 0)
        switching = false;

    // i쩨 정점과 i-1번째 정점이 연결되어 있지 않으면 유망하지 않다.
    else if (i > 0 && W[vindex[i - 1]][vindex[i]] == 0)
        switching = false;

    // 이전에 방문했던 정점이라면 유망하지 않다.
    else
    {
        switching = true;
        j = 1;
        while (j < i && switching)
        {
            if (vindex[i] == vindex[j])
                switching = false;
            j++;
        }
    }
    return switching;
}

void hamiltonian(int i)
{
    int j;
    if (promising(i))
    {
        if (i == 7)
        {
            for (int i = 0; i < 8; i++)
            {
                printf("%d ", vindex[i]);
            }
            printf("\n");
        }
        else
        {
            for (j = 2; j <= 8; j++)
            {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
            }
        }
    }
}
int main()
{
    hamiltonian(0);
    return 0;
}

/*
output:
1 2 3 4 5 6 7 8 
1 2 8 7 6 5 4 3
1 3 4 5 6 7 2 8
1 3 4 5 6 7 8 2
1 7 6 5 4 3 2 8 
1 8 2 3 4 5 6 7
1 8 2 7 6 5 4 3
1 8 7 6 5 4 3 2
*/