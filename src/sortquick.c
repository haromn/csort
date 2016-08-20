#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int in[100] = {1000,20,45,23,1,2,3,7,6,5,11,13,15,16,14,12,10,-1};
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
    int count = 0;
    printf("\n {");
    for (;*arr!=-1;arr++){
        count++;
        if (count>20) {
            printf(" ... ");
            break;
        }
        printf("%d,",*arr);
    }
    printf("} \n");
}

void acopy(int* source, int* target){
    for (;*source!=-1;*target++=*source++);
    *target=-1;
}

void bcopy(int* s, int* t,int n,int m){
    for (int i=n;i<m+1;i++){
        *(t+i-n)=*(s+i);
        if (*(s+i)==-1) return;
    }
    *(t+m+1-n)=-1;
}



void myqsort(int* arr) {
  int* smaller = malloc(50*sizeof(int));
  int* bigger = malloc(50*sizeof(int));
  int s=0;
  int b=0;
  int length = alen(arr);
  int center = arr[0];

  
  if (length<=1) {
    return;
  }

  for (int i=1; i<length;i++){
    if (arr[i]<=center) {
      smaller[s]=arr[i];
      s++;
    }
    else {
      bigger[b]=arr[i];
      b++;
    }
  }
  
  *(smaller+s)=-1;
  *(bigger+b)=-1;
  
  //aprint(smaller);
  //aprint(bigger);
  
  aprint(arr);
  printf("------------");
  aprint(smaller);
  aprint(bigger);
  printf("------------");

  myqsort(smaller);
  myqsort(bigger);

  acopy(smaller,arr);
  *(arr+s)=center;
  acopy(bigger,(arr+s+1));
  
  
  
  return;
}

void amerge(int* arr1, int* arr2, int* tmp){
    for (;;){
        if (*arr1 <= *arr2) {
            *tmp = *arr1;
            arr1++;
        }
        else {
            *tmp = *arr2;
            arr2++;
        }
        tmp++;
        if (*arr1==-1 || *arr2==-1) {
            break;
        }
    }
    if (*arr1==-1) {
        for (;*arr2!=-1;arr2++){
            *tmp=*arr2;
            tmp++;
        }
    }
    if (*arr2==-1) {
        for (;*arr1!=-1;arr1++){
            *tmp=*arr1;
            tmp++;
        }
    }
    *tmp=-1;
}



void mergesort(int* arr){
    int len = alen(arr);
    if (len==1) {
        return;
    }
    int hlen = len/2-1;
    int firsthalf[50];
    int secondhalf[50];
    bcopy(arr,firsthalf,0,hlen);
    bcopy(arr,secondhalf,hlen+1,100);
    mergesort(firsthalf);
    mergesort(secondhalf);
    amerge(firsthalf,secondhalf,arr);
    aprint(arr); //just for the show
    return;
}


void main(void){
  
  aprint(in);
  //mergesort(in);
  myqsort(in);
  aprint(in);




}
