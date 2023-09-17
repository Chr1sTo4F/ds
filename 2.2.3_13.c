int FindMissMin(int A[],int n){
    int i,*B;
    B=(int *)malloc(sizeof(int)*n);
    memset(B,0,sizeof(int)*n);
    for(i=0;i<n;i++)
        if(A[i>0 &&A[i]<n])
            B[A[i]-1]=1;
    for(i=0;i<n;i++)
        if(B[i]==0)
            break;
    return i+1;

}