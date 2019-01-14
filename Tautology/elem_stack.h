#ifndef _ELEM_STACK_H_
#define _ELEM_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "userDefine.h"

typedef struct Stack{
    char* base;   //ջ�ײ�ָ��
    char* top;     //ջͷָ��
    int stack_length;
}Sqstack;

void InitStack(Sqstack *s){
    s->base=(char*)malloc(sizeof(char)*STACK_SIZE); //�����ڴ�
    if(!s->base){
        printf("�����ڴ�ʧ��");
        return;
    }
    s->top=s->base;
    s->stack_length=STACK_SIZE;
}

bool IsEmpty(Sqstack s){
    if(s.base==s.top)
        return true;
    else return false;
}

char GetTopElem(Sqstack s){
    char elem;
    if(s.top==s.base){ //ջ���ж�
        return NULL;
    }
    elem=*(s.top-1); //��ջ��Ԫ�ظ�ֵ��elem
    return elem;
}


void PushElem(Sqstack* s,char elem){
    if(s->top-s->base>=s->stack_length){
        s->base=(char*)realloc(s->base,(s->stack_length+STACK_SIZE_ADD)*sizeof(char));
        if(!s->base){
            printf("�����ڴ�ʧ��!");
            return ;
        }
        s->top=s->base+s->stack_length;
        s->stack_length+=STACK_SIZE_ADD;
    }
    *(s->top++)=elem;
}

void PopElem(Sqstack* s,char* elem){
    if(s->base==s->top){
        printf("ջ��");
        return;
    }
    *elem=*(--s->top);
}



#endif // _ELEM_STACK_H_
