#include<stdio.h>
#include<string.h>

int in[40] = {1000,20,45,23,1,2,3,7,6,5,11,13,15,16,14,12,10,-1};
int in2[100] = {1,2,3,70,60,55,44,33,22,23,24,34,45,43,-1};

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

void aprint(int* arr){
    printf("\n {");
    for (;*arr!=-1;arr++){
        printf("%d,",*arr);
    }
    printf("} \n");
}


void insertsort(int* arr){
    int len = alen(arr);
    for (int i=1; i<len; i++){
        for (int j=i; j>0; j--){
            if (arr[j]<arr[j-1]) {
                aswap(arr,j,j-1);
                aprint(arr);
            }
            else {
                break;
            }
        }

    }

}


void main(void){
    aprint(in);

    insertsort(in);



}
