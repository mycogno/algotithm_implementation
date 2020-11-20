#include <stdio.h>

int arr[1000];

void exchange(int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void partition(int low, int high, int* pivotpoint){
    int i, j, pivotitem;

    //pivot값은 배열의 첫번째 값으로 선정한다.
    pivotitem = arr[low];
    j = low;
    for (i=low+1; i<=high; i++){
        // 2번째부터 j번째 원소까지 pivotitem보다 작은 값이 들어있도록 한다
        if (arr[i] < pivotitem){
            j++;
            exchange(i, j);
        }
    }
    // 최종적으로 pivotpoint를 j로 정하고 low위치의 값과 pivotpoint 값을 바꾼다.
    // pivotpoint를 기준으로 왼쪽은 작은 값, 오른쪽은 큰 값으로 나누었다.
    *pivotpoint = j;
    exchange(low, *pivotpoint);
}

void quicksort(int low, int high){
    int pivotpoint;
    if (high > low){
        partition(low, high, &pivotpoint);
        quicksort(low, pivotpoint - 1);
        quicksort(pivotpoint + 1, high);
    }
}

int main(){
    int n;
    int result = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quicksort(0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        if(!(i%2)) result = result + arr[i];
        else result = result - arr[i];
    }
    printf("%d\n", result);
    return 0;
}