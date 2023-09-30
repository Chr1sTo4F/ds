 #include <stdio.h>
 #include <stdlib.h>
 

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
//Day04
//对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素
/*
分析：O(n)扫描一次顺序表；O(1)申请常数个辅助空间
*/
void Del_x(SqList &L,ElemType x){
	int i=0,k=0;//k用来记录x的个数
	while(i<L.length){
		if(L.data[i] == x){
			k++;
		} else {
			L.data[i-k] = L.data[i];
		}
		i++;
	}
	L.length = L.length - k;
}
//方法二
//算法思想：变量顺序表,保留下不是x的值
void Del_x(SqList &L,ElemType x){
	int i=0,k=0;//k用来记录非x元素的个数
	if(L.data[i] != x){//如果不是x,保留
		L.data[k] = L.data[i];
		k++;
	}
	L.length = k;
}
//Day05
//从顺序表中删除其值在给定值s与t之间(包含s和t,要求s < t）的所有元素
//如果s或t不合理或顺序表为空,则显示出错信息并退出运行
bool Del_st(SqList &L,ElemType s,ElemType t){
	if(s>=t || L.length == 0){
		return false;
	}
	int i=0,k=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i]>=s && L.data[i] <=t ){
			k++;
		} else {
			L.data[i-k] = L.data[i];//将元素向前移动k个单位
		}
	}
	L.length = L.length - k;
	return true;
}
//Day06
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同
bool Del_same(SqList &L){
	if(L.length == 0){
		return false;
	}
	for(int i=0,j=1; j<L.length; j++){
		if(L.data[i]!=L.data[j]){
			L.data[++i] = L.data[j];
		}
	}
	L.length = i+1;
	return true;
}
//Day07
//已知在一维数组A[m+n]中依次存放网线个顺a表的位置互换,
//即将(b1, b2,b3...,bn)。试编写一个函数,
//将数组中两个顺序表的位置互换,即将(b1, b2,
//b3...bn)放在(a1, a2,a3..., am)的前面
void Reverse(ElemType A[],int i, int j){
	ElemType temp;
	for(int i=0;i < A.length/2;i++){
		temp = A.data[i];
		A.data[i] = A.data[A.length-i-1];
		A.data[A.length-i-1] = temp;
	}
}
void exchange(ElemType A[],int m,int n){//m:前m个元素，n：后n个元素
	Reverse(A,0,m-1);
	Reverse(A,m,m+n-1);
	Reverse(A,0,m+n-1);
}
//Day08
//2010统考真题
//算法思想：先将前p个元素逆置，然后将后n-p个元素逆置，最后将整个顺序表逆置
void Reverse(int R[],int from, int to){
	int temp,i;
	for(i=0;i<(to-from+1)/2;i++){
		temp = R[from + i];
		R[from + i] = R[to-i];
		R[to-i] = temp;
	}
}
void exchange(int R[],int m,int n){
	Reverse(R,0,p-1);
	Reverse(R,p,n-1);
	Reverse(R,0,n-1);
}
//时间复杂度分析：
//三句逆置代码分别为 O(p/2),O((n-p)/2),O(n/2)
//时间复杂度O(n),空间复杂度O(1)
 
//Day09
//试编写带头结点的的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
LinkList Delete_min(LinkList &L){
	LNode *pre = L,*p = L->next;
	LNode *minpre = pre,*minp = p;
	while(p){
		if(p->data < minp->data){//找到最小值结点
			minp = p;
			minpre = pre;
		} else {
			pre = p;
			p = p->next;
		}
	}
	minpre->next = minp->next;//删除最小值的结点
	free(minp);
	return L;
}
//Day10
//使用头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
	LNode *s,int x;//标记创建的新结点
	L = (LinkList)malloc(sizeof(LNode));//创建头结点
	L -> next = NULL;
	scanf("%d",&x);
	while(x!=-1){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}
//Day11
//使用尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));//创建头结点
	LNode *s,*r = L;//r为表尾指针,指向头结点
	//尾指针：当操作单链表表尾时，无需从头开始遍历，直接用尾指针进行增加结点
	scanf("%d",&x);
	while(x != -1){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//r指向新的表尾结点
		scanf("%d",&x);
	}
	r->next = NULL;//尾结点置空
	return L;
}
//Day12
//试编写算法将带头结点的单链表就地逆置，
//所谓的“就地”是指辅助空间的复杂度为O (1)
LinkList Reverse_LinkList(LinkList &L){
	LNode *p,*r;
	p = L->next;
	L->next = NULL;
	while(p!=NULL){
		r = p->next;//保存p的后继结点
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}
//方法二
LinkList Reverse_LinkList2(LinkList &L){
	LNode *pre = L->next,*p = pre->next,*r = p->next;
	while(r!=NULL){
		p->next = pre;
		pre = p;
		p = r;
		r = r->next;
	}
	L->next = p;
	return L;
}
 
//Day13
//设在一个带表头结点的单链表中所有元素的结点的数据值无序，试编写一个函数，
//删除表中所有介于给定的的两个值(作为函数的参数给出）之间的元素的元素(若存在)。
 
void Delete(LinkList &L,int min,int max){
	LNode *pre = L,*p = L->next;
	while(p!=NULL){
		if(p->data > min && p->data <max){
			pre->next = p->next;
			free(p);
			p = pre->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
}
//Day14(上)
//给定两个单链表，编写算法找出两个单链表的公共结点
LinkList search_common(LinkList &LA,linkList &LB){
	LNode *p = LA->next;
	LNode *q = LB->next;
	while(p){
		while(q){
			if(p == q){
				return p;
			} else {
				q = q->next;
			}
		}
		p = p->next;
		q = LB->next;//将q指针初始化到头结点的下一个结点
	}
	return NULL;//找不到就返回虚无
}
//时间复杂度：O(lenA * lenB)
 
//Day14(下)
//给定两个单链表，编写算法找出两个单链表的公共结点(优化算法)
LinkList search_common(LinkList &LA,LinkList &LB){
	LNode *p,*q;	
	int k;
	int lenA = length(LA);//求出链表长度
	int lenB = length(LB);
	if(lenA-lenB > 0){
		k = lenA - lenB;//求出链表的长度差
		p = LA->next;
		q = LB->next; 
	} else {
		k = lenB - lenA;
		p = LB->next;
		q = LA->next;
	}
	while(k--){
		p = p->next;//p先移动k个位置
	}
	while(p!=NULL){
		if(p == q){//若p==q，则找到公共结点
			return p;
		} else {
			p = p->next;//若不等，同步向后移动，可以同时到达表尾
			q = q->next;
		}
	}
	return NULL;//没有公共结点
}
//时间复杂度:O(max(lenA,lenB));
 
//Day15
//将一个带头结点的单链表A分解为两个带头结点的单链表A和B，
//使得A表中含有原表中序号为奇数的元素，
//而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
 
LinkList DisCreate(LinkList &A){
	LinkList B = (LinkList)malloc(sizeof(LNode));
	int i=0;
	B->next = NULL;//B表初始化
	LNode *ra = A,*rb = B,*p;
	p = A->next;
	A->next = NULL;
	while(p!=NULL){
		i++;
		if(i%2 == 0){
			rb->next = p;
			rb = p;
		} else {
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}
//Day16
//设C={a1，b1，a2，b2，...an，bn}为线性表，采用带头结点的hc单链表存放，
//设计一个就地算法，将其拆分为两个线性表，
//使得A={a1，a2，...， an},B={ bn，...，b2，b1}。
LinkList DisCreate2(LinkList &hc){
	LinkList A = (LinkList)malloc(sizeof(LNode));
	LinkList B = (LinkList)malloc(sizeof(LNode));
	A->next = NULL;
	B->next = NULL;
	//ra尾插法的尾指针
	LNode *ra = A,*p,*r;//这里是大师兄写错了，应该是*ra = A
	p = hc->next;//遍历指针
	hc->next = NULL;
	while(p!=NULL){
		//尾插先进行，头插后进行
		ra->next = p;
		ra = p;//尾指针不断指向表尾
		p = p->next;
		if(p){
			//头插法存在断链问题
			//*************
			//前后两句代码防止断链
			r = p->next;//头插后，*p将断链，r暂时保存p的后继
			p->next = B->next;
			B->next = p;
			p = r;
			//*************
		}
	}
	ra->next = NULL;
	return A,B;
}
 
 
//Day17
//在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，
//设计算法去掉数值相同的元素，使表中不再有重复的元素，
//例如 (7，10，10,21，30，42，42，42，51，70)将变成(7，10，21，30，42，51,70)
 
void Del_same(LinkList &L){
	LNode *pre = L->next;//pre指向第一个结点，第一个结点不可能重复
	LNode *p = pre->next;
	while(p){
		if(pre->data == p->data){
			pre->next = p->next;
			free(p);
			p = pre->next;
		} else {
			pre = p;
			p = p->next;
		}
	}
}
//另一种写法
void Del_same(LinkList &L){
	LNode *p = L->next,*q;
	while(p->next!=NULL){
		q = p->next;
		if(p->data == q->data){
			p->next = q->next;
			free(q);
		} else {
			p = p->next;
		}
	}
}
 
//Day18
//假设有两个按元素值递增次序排列的线性表，均以单链表的形式存储。
//请编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表，
//并要求利用原本两个单链表的结点存放归并后的单链表。
LinkList Merge(LinkList &A,LinkList &B){
	LNode *PA = A->next,*PB = B->next,*r;
	A->next = NULL;//将A的头指针置空
	while(PA!=NULL && PB!=NULL){
		if(PA->data < PB->data){
			r = PA->next;
			PA->next = A->next;
			A->next = PA;	
			PA = r;
		} else {
			r = PB->next;
			PB->next = A->next;
			A->next = PB;
			PB = r;
		}
	}
	while(PA){
		r = PA->next;
		PA->next = A->next;
		A->next = PA;
		PA = r;		
	}
	while(PB){
		r = PB->next;
		PB->next = A->next;
		A->next = PB;
		PB = r;	
	}
	return C;
}
 
//Day19
//设A和B是两个单链表(带头结点)，其中元素递增有序。
//设计一个算法从A和B中的公共元素产生单链表c，要求不破坏A、B的结点。
LinkList search_common(LinkList A,LinkList B){
	LinkList C = (LinkList)malloc(sizeof(LNode));
	C->next = NULL;
	LNode *p = A->next,*q = B->next,*r,*s;
	r = C;
	while(p && q){
		if(p->data < q->data){
			p = p->next;
		} else if(p->data > q->data){
			q = q->next;
		} else {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;//置C尾结点指针为空
	return C;
}
//Day20
//已知两个链表A和B分别表示两个集合，其元素递增有序排列。
//编制函数，求A和B的交集，并存放于A链表中。
//分析：元素递增；不能创建一个新链表，求完交集后，A链表中只有相同的元素(A&B的交集元素)
LinkList Union(LinkList &A,LinkList &B){
	LNode *p = A->next,*q = B->next;
	A->next = NULL;//尾插法的代码
	LNode *u,*r = A;//尾插法的代码
	while(p!=NULL && q!=NULL){
		if(p->data < q->data){
			u = p;
			p = p->next;
			free(u);
		} else if (q->data < p->data){
			u = q;
			q = q->next;
			free(u);
		} else {
			r->next = p;//保留p结点
			r = p;
			p = p->next;
			u = q;
			q = q->next;
			free(u);//释放q结点
		}
	}
	while(p){
		u = p;
		p = p->next;
		free(u);
	}
	while(q){
		u = q;
		q = q->next;
		free(u);
	}
	r->next = NULL;
	free(B);
	return A;
}
//Day21
//两个整数序列A=al，a2，a3 ...am和B=b1，b2，b3...，bn已经存入两个单链表中，
//设计一个算法，判断序列B是否是序列A的连续子序列。
bool son(LinkList A,LinkList B){
	LNode *p = A->next,*q = B->next;
	LNode *pre = p;//pre指针：尝试枚举所有可能
	while(p&&q){
		if(p->data != q->data){
			pre = pre->next;
			p = pre;//p从上次开始的后继结点在开始比较
			q = B->next;//q回到B的头结点的下一个结点
		} else {
			p = p->next;
			q = q->next;
		}
	}
	if(q == NULL){
		return true;
	} else {
		return false;
	}
}
//双链表的结点类型定义
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode, *DLinklist;
//Day22
//设计一个算法用于判断带头结点的循环双链表是否对称。
int Symmetry(DLinkList L){
	DNode *p = L->next,*q = L->prior;
	while(p!=q && p->next != q){
		//p!=q && q->prior != p
		if(p->data == q->data){
			p = p->next;
			q = q->prior;
		} else {
			return 0;
		}
	}
	return 1;
}
//Day23
//有两个循环单链表，链表头指针分别为h1和h2，
//编写一个函数将链表h2链接到链表h1之后，
//要求链接后的链表仍保持循环链表的形式。
LinkList Link(LinkList &h1,LinkList &h2){
	LNode *p,*q;
	p = h1;
	while(p->next != h1){
		p = p->next;//找到h1的表尾结点p
	}
	q = h2;
	while(q->next != h2){
		q = q->next;//找到h2的表尾结点q
	}
	p->next = h2;
	q->next = h1;
	return h1;
}
//Day24
//设有一个带头结点的的循环单链表，其结点值均为正整数。
//设计一个算法，反复找出单链表中结点值最小的结点并输出，
//然后将该结点从中删除直到单链表为空为止，再删除表头结点。
//提示：回顾Day09
void Del_All(LinkList &L){
	LNode *p,*pre,*minp,*minpre;
	while(L->next != L){//当头结点的后继指向自己时，循环终止
		//初始化指针位置
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while(p!=L){//从头结点的下一个结点出发，当再一次回到头结点时，跳出循环
			if(p->data < minp->data){
				minp = p;
				minpre = pre;
			} else {
				pre = p;
				p = p->next;
			}
		}
		printf("%d", minp->data);
		minpre -> next = minp -> next;
		free(minp);
	}
	free(L);//释放头结点
}
//Day25
//设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有pred
//(前驱指针)、data(数据)和next (后继指针)域外,个月一1回”受域freq。
//在链表被启用前，其值均初始化为零。每当在链表中进行一次Locate
//(L,x）运算时，令元素值为X的结点中freq域的值增加1，
//并使此链表中结点保持按访问频度非(递减)的顺序排列，
//同时，最近访问的结点拍在频度相同的结点前面，
//以便使频繁访问的结点总是靠近表头。
//使编写符合上述要求的Locate(L,x）运算的算法，
//该运算为函数过程，返回找到结点的地址，类型为指针型。
 
//非双循环链表的删除
p->next = q->next;
q->next->prior = p;
free(p);
//非双循环链表的插入
s->next = p->next;
p->next->prior = s;
s->prior = p;
p->next = s;
//注意：最后一步要放在前两步的后面(p->next域不能提前改变)
 
DLinkList Locate(DLinkList &L,ElemType x){
	DNode *p = L->next,*q;
	while(p!=NULL && p->data !=x ){
		p = p->next;
		if(p==NULL){
			printf("不存在值为x的结点");
			exit(0);//退出
		} else {//找到了x的值
			p->freq++;//频度+1
			//取下p
			if(p->next != NULL){
				p->next->pred = p->pred;
				p->pred->next = p->next;
			}
			//查找p的插入位置
			//q最多移动到头结点L处
			while(q!=L && q->fred <= p->fred){
				q = q->pred;//当q的频度小于p的频度，q继续往前移动，频度是递减排列的，
			}
			//这里是插入p指针
			p->next = q->next;
			if(q->next!=NULL)
				q->next->pred = p;
			p->pred = q;
			q->next = p;
		}
		return p;//返回值为x的指针
	}
}
//Day26
//2009年统考真题
//尽可能高效的算法：时间和空间
//思想：双指针，间隔一定，同步后移。定义两个指针变量p和q，
//初始时指向头结点的下一个结点，p指针先移动k个位置，然后q和p同时移动，
//当p移动到最后一个结点时(移动到NULL时)，q指针指向的是倒数第k个结点。
//链表的数据类型定义
typedef struct LNode{
	ElemType data;
	struct LNode *link;
}LNode,*LinkList;
int Search_k(LinkList list,int k){
	LNode *p = list->link,*q = list->link;//p&q指向第一个结点
	int count = 0;
	while(p!=NULL){
		if(count < k){
		count++;
		} else { 
			q = q->link;
		}
		p = p->link;//p先向后移动k个位置，然后p和q一起移动
	}
	if(count < k){//边界条件，当k过大
		return 0;
	} else {
		printf("%d",q->data);
		return 1;
	}
}
 
//Day27
//2012年统考真题
typedef struct SNode{
	char data;
	struct SNode *next;
}SNode;
int listlen(SNode *head){
	int len = 0;
	while(head->next != NULL){
		len++;
		head = head->next;
	}
	return len;
}
//这里两个求链表长度的函数，虽然工作指针起始位置不同，
//但是判空条件也不同，求的是除了头结点以外结点的长度
int listlen2(SNode *head){
	int len = 0;
	LNode *p = head->next;
	while(p != NULL){
		len++;
		p = p->next;
	}
	return len;
}
SNode* search_common(SNode *str1,SNode *str2){
	int m = listlen2(str1);
	int n = listlen2(str2);
	SNode *p,*q;
	for(p = str1;m>n;m--){
		p = p->next;
	}
	for(q = str2;m<n;n--){
		q = q->next;
	}
	while(p!=NULL && p!=q){
		p = p->next;
		q = q->next;
	}
	return p;
	// if(p == NULL){
	// 	return NULL;
	// } else {
	// 	return p;
	// }
}
//Day28
//2015年统考真题
//单链表结点的数据类型定义
typedef struct node {
	int data;
	struct node *link;
}Node;
 
//用空间换时间
//时间复杂度：O(m);空间复杂度：O(n);
void function(LinkList &head,int n){
	Node *p = head->link,*pre = head;
	int* C,m;
	C = (int*)malloc(sizeof(int )*(n+1));
	for(int i=0;i<=n;i++){
		C.data[i] = 0;
	}
	while(p!=NULL){
		m = p->data>0 ? p->data : -(p->data);
		if(C.data[m]==0){//当第一次出现某个数，将标记数组改为1，保留该数字
			C.data[m] = 1;
			pre = p;
			p=p->link
		} else {
			pre->link = p->link;
			free(p);
			p = pre->link;
		}
	}
	free(C);//释放辅助数组
}
 
//Day29
//2019年统考真题
//算法思想：先找到单链表的中间结点，将后半段逆置，然后将后半段插入到前半段合适的位置
 
void change_lsit(Node *h){
	Node *p,*q,*s,*r;
	p=q=h;
	//找到中间结点
	while(q->next != NULL){
		p = p->next;
		q = q->next;
		if(q->next != NULL){//当下一步不为虚无，q再走一步
			q = q->next;
		}
	}
	//逆置单链表的后半段
	q = p->next;
	p->next = NULL;
	while(q!=NULL){
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	s = h->next;
	//后半链表插入到前半段链表
	s = h->next;//s指向前半段第一个结点
	q = p->next;//q指向后半段第一个结点
	p->next = NULL;
	while(q!=NULL){
		r = q->next;//防止断链
		q->next = s->next;
		s->next = q;
		s = q->next;//s指向下下个结点，因为插入了一个结点
		q = r;//防止断链
	}
}
//Day30
/*
总结：
1. 头插法
2. 尾插法
3. 逆置法(顺序表和单链表)
4. 归并法(分解)
5. 双指针法(取较小结点合成链表，倒数第K个元素，中间元素)
6. 双循环链表法(插入和删除，注意断链问题)
*/
//Day31
//已知一棵二叉树按顺序存储结构进行存储，设计一个算法，
//求编号分别为i和j的两个结点的最近公共祖先结点的值。
//算法思想：不断将较大的i和j取一半，直到i=j，找到了最近的公共祖先结点
ElemType Comn_Ancestor(SqTree T,int i,int j){
    //这里的i!=j是在找到公共祖先结点后退出循环的条件
	while(T[i] != NULL && T[j] != NULL && i!=j){
 
		while(i!=j){
			if(i>j){
				i=i/2;
			}else{
				j=j/2;
			}
		}
	}
	return T[i];
}
//Day32
//二叉树的链式存储
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//先序遍历
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
/*无论采用哪—种遍历算法，每个结点都访问一次,且仅访问一次，
故时间复杂度都是O (n)。在递归遍历算法中，递归工作栈的栈深恰好为树的深度，
所以最坏的情况下，二叉树是有n个结点且深度为n单支树，遍历算法的空间复杂度为O (n)
★凡事：都要考虑好最坏的情况，比如表白~★
 */
//Day33
//递归和非递归之间的转换问题？为什么要将递归算法转化为非递归？
//中序遍历的非递归算法
void InOrder2(BiTree T){
	InitStack(S);
	BiTree p = T;
	while(p!=NULL || !IsEmpty(S)){//有一个不为空就继续循环
		if(p){
			push(S,p);
			p = p->lchild;//一路向左走
		} else {
			Pop(S,p);//找到二叉树最左边的结点 
			visit(p);
			p = p->rchild;
		}
	}
	//口诀：入栈一直向左走，出栈访问右子树 
}
//Day34
//后序遍历的非递归算法
//算法思想：
//1. 沿着跟的左孩子，依次入栈，知道左孩子为空
//2. 读栈顶元素，若其右孩子不空且未被访问，将右孩子执行1
//3. 栈顶元素出栈
bool GetTop(SqStack S,ElemType &x){
	if(S.top == -1){
		return false;
	}
	x = S.data[S.top];//x记录栈顶元素
	return true;
}
void PostOrder(BiTree T){
	InitStack(S);
	p = T;
	r = NULL;//r指针标记最近访问的结点
	while(p || !IsEmpty(S)){
		if(p){
			Push(S,p);
			p = p->lchild;
		} else {
			GetTop(S,p);//读取栈顶结点
			//读栈定元素的作用就是找下一个结点
			if(p->rchild!=NULL && p->rchild!=r){
				//如果右子树不为空且未被访问过，执行1的操作
				p = p->rchild;
				push(S,p);
				p = p->lchild;
			} else {
				pop(S,p);
				visit(p->data);
				r = p;
				//当递归到最左边的叶子结点入栈，出栈并访问后，此时的P还指向它，
				//此时应对P置空，否则就又把它压进栈里面了
				//不重置，栈顶元素会无限入栈出栈
				//因为要去出栈了 p=null后if就不成立了了，直接调到else在出栈
				//因为要判断栈顶，p不为空不能执行else里面的gettop
				p = NULL;//结点已经出栈，置空处理,
			}
		}
	}
}
//Day35
//二叉树层次遍历算法
void LevelOrder(BiTree T){
	InitQueue(Q);
	BiTree p=T;
	Enqueue(Q,T);//根结点入队
	while(!IsEmpty(Q)){
		DeQueue(Q,p);
		visit(p);
		if(p->lchild){
			Enqueue(Q,p->lchild);
		}
		if(p->rchild){
			Enqueue(Q,p->rchild);
		}
	}
}
//Day36
//给出二叉树的至下而上、从右到左的层次遍历算法
void LevelOrder(BiTree T){
	Stack s;Queue q;
	if(T != NULL){
		InitQueue(Q);
		InitStack(S);
		BiTree p;
		Enqueue(Q,T);
		while(!IsEmpty(Q)){
			DeQueue(Q,p);
			push(S,p);
			if(p->lchild){
				Enqueue(Q,p->lchild);
			}
			if(p->rchild){
				Enqueue(Q,p->rchild);
			}
		}
		while(!IsEmpty(S)){
			pop(S,p);
			visit(p->data);
		}
	}
}
//Day37
//假设二叉树采用二叉链表存储结构，设计一个算法求二叉树的高度(递归和非递归)
//递归	
int depth(BiTree b){
	if(b==NULL){
		return 0;
	}
	int ldep = depth(b->lchild);//左子树高度
	int rdep = depth(b->rchild);//右子树高度
	//返回左右子树中更高的子树的高度 + 1，递归出口是左右子树为虚无
	return (ldep > rdep ? ldep : rdep)+1;
}
//非递归
int Btdepth(BiTree T){
	if(!T){
		return 0;
	}
	int last=0,level=0;
	int front = rear = -1;
	BiTree Q[MaxSize];
	BiTree p;
	Q[++rear] = T;//根结点入队
	while(front < rear){
		p = Q[++front];
		if(p->lchild){
			Q[++rear] = p->lchild;
		}
		if(p->rchild){
			Q[++rear] = p->rchild;
		}
		if(front == last){
			level++;
			last = rear;
		}
	}
	return level;
}
//Day38
//设树B是一棵采用链式结构存储的二叉树，编写一个把树中所有结点的左右子树交换的函数。
//思想：递归的交换左右子树
void swap(BiTree b){
	if(b!=NULL){
		swap(b->lchild);
		swap(b->rchild);
		temp = b->rchild;
		b->rchild = b->lchild;
		b->lchild = temp;
	}
}
//Day39
// 假设二叉树采用二叉链表存储结构存储，试设计一个算法，
// 计算一棵给定二叉树的所有双分支(度为2)结点个数。
int DoubleNodes(BiTree b){
	if(b == NULL){
		return 0;
	} else if(b->lchild != NULL && b->rchild != NULL){//双分支结点
		//根结点有左右子树，根结点是度为2的结点
		return DoubleNodes(b->lchild)+DoubleNodes(b->rchild)+1;
	} else {
		return DoubleNodes(b->lchild) + DoubleNodes(b->rchild);
	}
}
// 思考题：统计二叉树度为1的结点个数
int Degree_1(BiTree b){
	if(b == NULL){
		return 0;
	} else if(b->lchild != NULL && b->rchild != NULL){
		return Degree_1(b->lchild)+Degree_1(b->rchild);
	} else {
		return Degree_1(b->lchild)+Degree_1(b->rchild)+1;
	}
}
// 思考题：统计二叉树度为0的结点个数
int NumsDegree_0(BiTree T)
{
	if(T!=NULL)
	{
		if(T->left == NULL && T->right == NULL)
			return 1;
		else
			return NumsDegree_0(T->left)+NumsDegree_0(T->right);
	}
	else
		return 0;
}
// 统计二叉树度为1的结点个数
int NumsDegree_1(BiTree T)
{
	if(T)
	{
		if((T->left && T->right==NULL) || (T->right && T->right==NULL))
			return NumsDegree_1(T->left) + NumsDegree_1(T->right) +1;
		else
			return NumsDegree_1(T->left) + NumsDegree_1(T->right);
	}
	else
		return 0;
}
 
int NumsDegree_2(BiTree T)
{
	if(T)
	{
		if(T->left && T->right)
			return NumsDegree_2(T->left) + NumsDegree_2(T->right) +1;
		else
			return NumsDegree_2(T->left) + NumsDegree_2(T->right);
	}
	else
		return 0;
}
 
//Day40
//计算二叉树所有的结点个数
int count(BTNode *p){
	if(b == NULL){
		return 0;
	}
	return 1 + count(b->rchild) + count(b->lchild);
}
//方法二
int n = 0;
void count(BTNode *p){
	if(p!=NULL){
		n++;
		count(p->lchild);
		count(p->rchild);
	}
}
 
//Day41
//假设二叉树采用二叉链存储结构存储，设计一个算法，
//求先序遍历序列中第K(1 ≤ K ≤ 二叉树中结点个数)个结点的值。
int n = 0;//定义全局变量
void PreOrder(BTNode *p,int k){
	if(p!=NULL){
		++n;
		if(n==k){
			printf("%d",p->data);
			return;
		}
		PreOrder(p->lchild,k);
		PreOrder(p->rchild,k); 
	}
}
//Day42
//计算二叉树中所有的叶子结点个数
int num(BiTree b){
	if(b==NULL){
		return 0;
	}
	//递归边界
	if(b->lchild == NULL && b->rchild == NULL){
		return 1;
	} else {
		return num(b->lchild) + num(b->rchild);
	}
}
int n=0;
int PreOrder(BTNode *p){
	if(!p){
		return 0;
	}
	if(p->lchild == NULL && p->rchild == NULL){
		++n;
	}
	PreOrder(p->lchild);
	PreOrder(p->rchild);
	return n;
}
// Day43
// 查找二叉树中data域等于key的结点是否存在，
// 若存在，将q指向它否则q为空。
void fun(BTNode *bt,BTNode q,int key){
	if(bt!=NULL){
		if(bt->data = key){
			q = bt;
			return;//找到key就结束递归
		} else {
			fun(bt->lchild,q,key);
			fun(bt->rchild,q,key);
		}
	}
}
//Day44
//利用结点的右孩子指针lchild,将一个二叉树的叶子结点从左向右链接成一个单链表
//(head指向第一个，tail指向最后一个)
void link(BTNode *p,BTNode *head,BTNode *tail){
	if(p!=NULL){
		if(p->lchild == NULL && p->rchild == NULL){
			if(head == NULL){
				head = p;
				tail = p;
			} else {
				tail->rchild = p;
				tail = p;
			}
		}
		link(p->lchild,head,tail);
		link(p->rchild,head,tail);
	}
}
//Day45
//若二叉树采用链式存储结构，设求出指定结点p在给定二叉树排序树的层次
int level(BTNode *bt,BTNode *p){
	int n=1;
	BTNode *t = bt;//遍历指针
	if(bt!=NULL){
		while(t->data != p->data){
			if(t->data < p->data){
				t = t->rchild;
			} else {
				t = t->lchild;
			}
			++n;
		}
	}
	return n;
}
 
//Day46
//2014年统考真题
//二叉树结点的数据类型定义
typedef struct BTNode {
	int weight;
	struct BTNode *lchild,*rchild;
}BTNode,*BiTree;
//基于先序遍历的算法
int wpl_preorder(BiTree root,int deep){
	static int wpl = 0;
	if(root->lchild == NULL && root->rchild == NULL){
		wpl+=deep * root->weight;
	}
	if(root->lchild != NULL){
		wpl_preorder(root->lchild,deep+1);
	}
	if(root->rchild != NULL){
		wpl_preorder(root->rchild,deep+1);
	}
	return wpl;
}
int wpl(BiTree root){
	return wpl_preorder(root,0);//调用先序遍历的算法，求wpl
}
//Day47
//2017年统考真题
//思想：根节点不加括号，叶子结点不加括号，其他结点加括号
void InOrderfun(BTNode *root,int deep){
	if(!root){
		return;
	} else if (root->lchild==NULL && root->rchild == NULL){
		printf("%s",root->data);
	} else {
		if(deep > 1){
			printf("(");
		}
		InOrderfun(root->lchild,deep+1);
		printf("%s",root->data);
		InOrderfun(root->rchild,deep+1);
		if(deep > 1){
			printf(")");
		}
	}
}
void fun(BTNode *root){
	InOrderfun(root,1);
}
//Day48
//假设二叉树采用二叉链表结构存储，设计一个算法，求二叉树中值为x的层号。
void fun(BTNode *p,int x){
	static int h = 0;
	if(p!=NULL){
		if(p->data == x){
			printf("%d",h);
		}
		++h;//进入左子树+1，向下走
		fun(p->lchild);
		//横向走
		fun(p->rchild);
		--h;//出右子树-1，向上走
	}
}
//Day49
//请设计一个算法，增加一个指向双亲结点的parent指针，
//并给指向指针赋值，并输出所有结点到根结点的路径
 
//二叉树数据类型定义
typedef struct BTNode {
	char data;
	struct BTNode *parent,*lchild,*rchild;
}BTNode;
//1. 给二叉树增加一个指向双亲的指针parent
void add_parent(BTNode *p,BTNode *q){
	if(p!=NULL){
		p->parent = q;
		q = p;
		add_parent(p->lchild,q);
		add_parent(p->rchild,q);
	}
 
}
//2. 打印单个结点到根结点的路径
void print_path(BTNode *p){
	while(p!=NULL){
		printf("%c",p->data);
		p = p->parent;
	}
}
//3. 打印所有结点到根结点的路径
void print_all_path(BTNode *p){
	if(p!=NULL){
		print_path(p);
		print_all_path(p->lchild);
		print_all_path(p->rchild);
	}
}
//Day50
//已知一棵二叉树链式存储，请设计一个算法，输出根结点到每个叶子结点的路径
int i=0,top=0;
ElemType stack[MaxSize];
void path(BTNode *p){
	if(p != NULL){
 		stack[top] = p->data;//入栈
		++top;//指针上移
		if(p->lchild==NULL && p->rchild == NULL){//叶子结点，读取栈中元素
			for(int i=0;i<top;i++){//遍历
				printf("%c",stack[i]);
			}
		}
		path(p->lchild);
		path(p->rchild);
		--top;//出栈
	}
}
 