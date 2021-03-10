#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
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