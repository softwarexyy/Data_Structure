/**********快速排序***********/

#include <stdio.h>
#define SIZE 5

int partition(int array[],int p,int q);         //p到q之间划分区间，返回pivot所在位置的下标
void quicksort(int array[],int p,int q);     //快速排序
void swap(int *a,int *b);                       //交换元素值

int main(){
    int i,array[SIZE];
    printf("Input %d numbers:",SIZE);
    for(i=0;i<SIZE;i++)
        scanf("%d",&array[i]);
    quicksort(array,0,SIZE-1);
    printf("After quicksort: ");
    for(i=0;i<SIZE;i++)
        printf("%d ",array[i]);
    return 0;
}

int partition(int array[],int p,int q){
    int pivot = array[q];
    int pivot_position;
    int i=p,j=p-1;
    for(i=p;i<q;i++){
        if(array[i]<=pivot){
            j++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&(array[q]),&(array[j+1]));
    return (j+1);
}

void quicksort(int array[],int p,int q){
    if(p<q){
        int r = partition(array,p,q);
        quicksort(array,0,r-1);         //递归实现quicksort
        quicksort(array,r+1,q);
    }
}

void swap(int* a,int* b){
    int c= *a;
    *a = *b;
    *b = c;
}
