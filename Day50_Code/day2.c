//Day02
//将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表
bool Merge(SqList A,SqList B,SqList C){
	if(A.length + B.length > C.length){
		return false;
	}
	int i=0,j=0,k=0;
	while(i<A.length && j<B.length){
		if(A.data[i]<B.data[j]){
			C.data[k] = A.data[i];
			i++;k++;
		}else{
			C.data[k] = B.data[j];
			j++;k++;
		}
	}
	while(i<A.length){
		C.data[k++] = A.data[i++];
	}
	while(j<B.length){
		C.data[k++] = B.data[j++];
	}
	C.length = k+1;
	return true;
}