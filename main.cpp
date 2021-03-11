#include <iostream>
#include "Sort.h"
int main() {
    int a[]={0,3,1,4,29,8,5,6};
    insertSort(a,8);
    return 0;
}
//选择排序
void selectSort(int R[],int n){
    int i,j,k;
    int tmp;
    for(i=0;i<n;++i){
        k=i;
        for(j=i+1;j<n;++j)
            if(R[i]>R[j])
                k=j;
        tmp=R[j];
        R[j]=R[i];
        R[i]=tmp;
    }
}