#include<stdio.h>
#include<string.h>

int tomb[40] = {1000,20,45,23,1,2,3,7,6,5,11,13,15,16,14,12,10,-1};
int tomb2[100] = {10,5,1,4,7,6,2,3,9,8,-1};

int alen(int* arr){
    int i=0;
    for (;*arr!=-1;arr++,i++){}
    return i;
}

void aswap(int* arr, int i, int j){

    int tmp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = tmp;

}

void aprint(int* arr);

void selectionsort(int* arr){
    int len = alen(arr);
    int minind = 0;
    for (int i=0; i<len; i++){
        minind = i;
        for (int j=i; j<len; j++){
            if (arr[j]<arr[minind]) {
                minind = j;
            }
        }
        if (i!=minind) {
            aswap(arr,i,minind);
            aprint(arr);
        }
    }

}

void aprint(int* arr){
    printf("\n {");
    for (;*arr!=-1;arr++){
        printf("%d,",*arr);
    }
    printf("} \n");
}

void main(void){
    aprint(tomb);

    selectionsort(tomb);



}
