//Day03
//设计一个高效算法,将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1)
void Reverse(SqList &L){
	ElemType temp;
	for(int i=0;i<L.length/2;i++){
		temp = L.data[i];
		L.data[i] = L.data[L.length-i-1];
		L.data[L.length-i-1] = temp;
	}
}
//递归法
void Reverse(int* A,int low,int high){
	if(low < high){
		swap(A[low],A[high]);
		Reverse(A,low+1,high-1);
	}
}