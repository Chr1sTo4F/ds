#include <stdio.h>
#include <stdbool.h>

bool Judge(char A[]){
    int i=0,j=0,k=0;
    while(A[i]!='\0'){
        switch (A[i])
        {
        case 'I': 
            j++; 
            break;
        case 'O':
            k++;
            if(k>j){
                printf("非法序列\n");
            }
        }
        i++;
    }
    if(j!=k){
        printf("非法序列\n");
        return false;
    }
    else{
        printf("合法序列\n");
        return true;
    }
    
}