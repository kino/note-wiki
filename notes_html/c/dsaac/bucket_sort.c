#include<stdio.h>
#define random(x) (rand()%x)
#define M 10000
#define AL1 10
#define AL2 20


void BucketSort(int arr[], int length){
    int i, j, k,  count[M]={0};

    for(i = 0; i < length; i++){
        count[arr[i]] += 1;
    }

    j=0;
    for(i = 0; i < M; i++){
        for(k = 0; k < count[i]; k++){
            arr[j]=i;
            j++;
        }
    }
}

void PrintArr(const int arr[], int length){
    int i;

    for(i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main(){
    int i,arr1[AL1], arr2[AL2];
    srand(time(0));

    for(i = 0; i < AL1; i++){
        arr1[i]=random(M);
    }

    for(i = 0; i < AL2; i++){
        arr2[i]=random(M);
    }

    printf("Before sort arr1:\n");
    PrintArr(arr1, AL1);
    BucketSort(arr1, AL1);
    printf("After sort arr1:\n");
    PrintArr(arr1, AL1);

    printf("Before sort arr2:\n");
    PrintArr(arr2, AL2);
    BucketSort(arr2, AL2);
    printf("After sort arr2:\n");
    PrintArr(arr2, AL2);
    
}

