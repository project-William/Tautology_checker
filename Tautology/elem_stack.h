#ifndef _ELEM_STACK_H_
#define _ELEM_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "userDefine.h"

typedef struct Stack{
    char* base;   //Õ»µ×²¿Ö¸Õë
    char* top;     //Õ»Í·Ö¸Õë
    int stack_length;
}Sqstack;

void InitStack(Sqstack *s){
    s->base=(char*)malloc(sizeof(char)*STACK_SIZE); //·ÖÅäÄÚ´æ
    if(!s->base){
        printf("·ÖÅäÄÚ´æÊ§°Ü");
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
    if(s.top==s.base){ //Õ»¿ÕÅÐ¶Ï
        return NULL;
    }
    elem=*(s.top-1); //½«Õ»¶¥ÔªËØ¸³Öµ¸øelem
    return elem;
}


void PushElem(Sqstack* s,char elem){
    if(s->top-s->base>=s->stack_length){
        s->base=(char*)realloc(s->base,(s->stack_length+STACK_SIZE_ADD)*sizeof(char));
        if(!s->base){
            printf("·ÖÅäÄÚ´æÊ§°Ü!");
            return ;
        }
        s->top=s->base+s->stack_length;
        s->stack_length+=STACK_SIZE_ADD;
    }
    *(s->top++)=elem;
}

void PopElem(Sqstack* s,char* elem){
    if(s->base==s->top){
        printf("Õ»¿Õ");
        return;
    }
    *elem=*(--s->top);
}



#endif // _ELEM_STACK_H_
