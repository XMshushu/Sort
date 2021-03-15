
//直接插入算法
void insertSort(int R[],int n){
    int i,j;
    int temp;
    for(i=1;i<n;i++){
        j=i-1;
        temp=R[i];
        while (j>=0&&temp<R[j]){
            R[j+1]=R[j];
            --j;
        }
        R[j+1]=temp;
    }
}
//折半插入排序
//希尔排序

//气泡排序
void bubbleSort(int R[],int n){
    int i,j,flag;
    int temp;
    for(i=n-1;i>=1;--i) {
        flag=0;
        for (j=1;j<=i;++j)
            if(R[j-1]>R[j]) {
                temp=R[j-1];
                R[j-1]=R[j];
                R[j]=temp;
                flag=1;
            }
        if(flag==0)
            break;
    }
}

//快速排序
void quickSort(int R[],int low,int high){
    int temp;
    int i=low,j=high;
    if (low<high){
        temp=R[low];
        while (i<j){
            while (i<j&&R[j]>=temp) --j;
            if(i<j){
                R[i]=R[j];
                ++i;
            }
            while (i<j&&R[i]<temp) ++i;
            if(i<j){
                R[j]=R[i];
                --j;
            }
        }
        R[i]=temp;
        quickSort(R,low,i-1);
        quickSort(R,i+1,high);
    }
}
//二路归并排序的合并算法
void merge(int R[],int low,int mid,int high){
    int i=mid+1,j,last=mid;
    int temp;
    while (i<=high&&R[i]<R[i-1]){
        for(j=i;j>low;--j){
            if(R[j]<R[j-1]){
                temp=R[j];
                R[j]=R[j-1];
                R[j-1]=temp;
            }
        }
        ++i;
    }
}
//二路归并排序
//空间复杂度n+log2n=O(n)
void mergeSort(int R[],int low,int high){
    if(low<high){
        int mid=(high+low)/2;
        mergeSort(R,low,mid);
        mergeSort(R,mid+1,high);
        merge(R,low,mid,high);
    }
}
//第二种实现
//void merge(int R[],int low,int mid,int high){
//    int i,j,stop=low;
//    int temp;
//    for(i=mid+1;i<=high;++i){
//        for(j=i;j>stop;--j){
//            if(R[j]<R[j-1]){
//                temp=R[j];
//                R[j]=R[j-1];
//                R[j-1]=temp;
//            }else{
//                stop=j+1;
//            };
//        }
//    }
//}
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

//堆排序
void Shit(int R[],int low,int high){
    int i=low,j=2*i,tmp=R[i];
    while (j<=high){
        if(j<high&&R[j]<R[j+1]) ++j;
        if(tmp<R[j]){
            R[i]=R[j];
            i=j;
            j=2*i;
        } else break;
    }
    R[i]=tmp;
};
//堆排序主程序
void heapSort(int R[],int n){
    int i,tmp;
    for(i=n/2;i>=0;--i){
        Shit(R,i,n);
    }
    for(i=n;i>0;--i){
        tmp=R[0];
        R[0]=R[i];
        R[i]=tmp;
        Shit(R,0,i-1);
    }
}

//真题仿造1
void resort(int R[],int n){
    int i=0,j=n-1,temp;
    while (i<j){
        while (i<n&&R[i]<0) ++i;
        while (j>i&&R[j]>0) --j;
        temp=R[i];
        R[i++]=R[j];
        R[j--]=temp;
    }
}