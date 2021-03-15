

//顺序查找
int search(int a[],int n,int k){
    int i;
    for(i=0;i<n;++i)
        if (a[i]==k)
            return i;
    return -1;
}
//折半查找法
int BSearch(int a[],int low,int high,int k){
    int mid=(high+low)/2;
    while (low<=high){
        if(mid==k)
            return mid;
        else if(mid>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}