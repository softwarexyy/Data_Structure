/***********堆排序*************/

#include <stdio.h>
#define SIZE 5

void heapsort(int array[],int heapsize);
void max_heapify(int array[],int i,int heapsize);   //维护最大堆性质
void build_max_heap(int array[],int heapsize);      //建堆
int parent(int i);            //计算父结点下标
int lchild(int i);              //计算左孩子结点下标
int rchild(int i);             //计算右孩子结点下标

int main(){
    int i;
    int array[SIZE];
    printf("Please input the %d numbers : ",SIZE);
    for(i=0;i<SIZE;i++){
        scanf("%d",&array[i]);
    }
    heapsort(array,SIZE);       //堆排序

    printf("After the heapsort: ");
    for(i=0;i<SIZE;i++){
        printf("%d  ",array[i]);
    }
    return 0;
}

void heapsort(int array[],int heapsize){
    int i,max;
    build_max_heap(array,heapsize);
    for(i=heapsize-1;i>=0;i--){
        max =  array[0];
        array[0]  = array[i];
        array[i] = max;
        max_heapify(array,0,i);
    }
}


void max_heapify(int array[],int i,int heapsize){
    int lch = lchild(i);          //左孩子下标
    int rch = rchild(i);          //右孩子下标
    int max = 0;
    int swap = -1;              //交换用的中间变量

    if(lch<heapsize&&array[lch]>array[i])
        max = lch;
    else
        max = i;

    if(rch<heapsize&&array[rch]>array[i])
        max = rch;

    if(max != i){
        swap = array[max];
        array[max] = array[i];
        array[i] = swap;
        max_heapify(array,max,heapsize);
    }

}


void build_max_heap(int array[],int heapsize){
    int i = parent(heapsize-1);     //起点的下标
    for(i;i>=0;i--)
        max_heapify(array,i,heapsize);
}


int parent(int i){
    return ((i-1)/2);
}

int lchild(int i){
    return (i*2+1);
}

int rchild(int i){
    return (i*2+2);
}
