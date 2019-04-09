#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
int InputExp(char *expression,int var_num);   //用户输入表达式
void InputElemVarible(int *elem_varible,int num);//用户输入可满足式的变量值


void InputElemVarible(int *elem_varible,int num){
    for(int i=0;i<num;i++)
        scanf("%d",&elem_varible[i]);
}

int InputExp(char *expression,int var_num){
    char c;
    int i=0;
    while(c!='#'){
        c=getchar();
        expression[i++]=c;
        var_num++;
    }
    return var_num;
}

#endif // _USER_H_
