#define maxsize 100
#define ElemType int 
typedef struct 
{
    ElemType stack[maxsize];
    /* top为两个栈顶指针 */
    int top[2];
    
}stk;
stk s;
/* 入栈 */
int push(int i,ElemType x){
    //入栈操作。i为栈号，i=0 表示左边的s1栈，i=1表示右边的 s2 栈，×是入栈元素
    //入栈成功返回1，否则返回0
    if(i<0 || i>1){
        printf("栈号输入错误\n");
        exit(0);
    }
    if(s.top[1]-s.top[0]==1){
        printf("栈满\n");
        retuen 0;
    }
    switch (i)
    {
    case 0:
        s.stack[++s.top[0]] = x;
        return 1;
        break;
    
    case 1:
        s.stack[--s.top[1]]=x;
        return 1; 
        break;
    }

}

/* 退栈 */
ElemType pop(int i){
    //退栈算法。i代表栈号，i=0时为s1 栈，i=1时为s2栈 
    //退栈成功返回退栈元素，否则返回-1
    if(i<0 || i>1){
        printf("栈号输入错误\n");
        exit(0);
    }
    switch (i)
    {
    case 0:
        if(s.top[0]==-1){
            printf("empty\n");
            return -1;
        }
        else
            return s.stack[s.top[0]--];
        break;
    
    case 1:
        if(s.top[1]==maxsize){
            printf("empty\n");
            return -1;
        }
        else 
        return s.stack[s.top[1]++];
        break;
    }

}