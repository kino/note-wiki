#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#define AL1 10
#define AL2 100000
#define M 10000000
#define random(x) (rand()%x)

struct ElementStruct;
typedef struct ElementStruct *Element, *Bucket;

struct ElementStruct{
    int Value;
    Element Next;
};
     


//x^n
int Power(int x, int n){
    if(n==0){
        return 1;
    }else if(n==1){
        return x;
    }else{
        if(n%2==0){
            return Power(x*x, n/2);
        }else{
            return Power(x*x, n/2)*x;
        }
    }
}

void AddToBucket(Bucket *b, int element){
    Element temp;
    if((*b)==NULL){
        *b = malloc(sizeof(*temp));
        (*b)->Value = element;
        (*b)->Next = NULL;
    }else{
        temp = *b;
        while(temp->Next!=NULL){
            temp = temp->Next;
        }

        temp->Next = malloc(sizeof(*temp));
        temp->Next->Value = element;
        temp->Next->Next = NULL;
    }
}

int RetrieveFromBuckets(Bucket *b, int len){
    int i, e;
    Element temp;

    for(i = 0; i < len; i++){
        if(b[i]!=NULL){
            temp = b[i];
            b[i] = temp->Next;

            e = temp->Value;
            free(temp);

            return e;
        }
    }
    return -1;
}


void RadixSort(int arr[], int length, int R, int X){
    int i, j, k, e,  base;
    Bucket buckets[R], buckets2[R], *temp, *b, *b2;

    memset(buckets, (int)NULL, R*sizeof(Bucket));
    memset(buckets2,(int)NULL, R*sizeof(Bucket));

    b = buckets, b2 = buckets2;

    for(j=0; j < length; j++){
        AddToBucket(b2, arr[j]);
    }

    for(i=0; i < X; i++){
        //The i backet sort
        base = Power(R, i);

        e = RetrieveFromBuckets(b2, R);
        while(e>0){
            k = e/base%R;
            AddToBucket(&(b[k]), e);
            e = RetrieveFromBuckets(b2, R);
        }

        temp = b2;
        b2 = b;
        b = temp;
    }

    i=0;
    e = RetrieveFromBuckets(b2, R);
    while(e>0){
        arr[i++] = e%base;
        e = RetrieveFromBuckets(b2, R);
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
    RadixSort(arr1, AL1, 10, 9);
    printf("After sort arr1:\n");
    PrintArr(arr1, AL1);

    printf("Before sort arr2:\n");
    PrintArr(arr2, AL2);
    RadixSort(arr2, AL2, 10, 9);
    printf("After sort arr2:\n");
    PrintArr(arr2, AL2);
    
}
