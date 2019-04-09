#ifndef _OPERATE_H_
#define _OPERATE_H_
#include <math.h>
#include "userDefine.h"
#include "oper_biTree.h"
#include "user.h"

int m=0;
enum Boolean{True,False};


//操作模块函数
void ExpressionVarible(char* expression,char* varibleList,int num);  //将表达式中的逻辑变量另外存储以便进行全排列取值
void Transform(char* expression,Sqstack* s);                         //将用户输入的逻辑表达式转化为后缀表达式
void ExpVarPermutation(char* varible_list);                         //逻辑变量的全排列


//计算逻辑变量的全排列
void ExpVarPermutation(Boolean b[],int var_num,int k,int permu_var[]){
    if(k == var_num){
        if(m==0){
            for(int i=0;i<var_num;i++){
                permu_var[i]=b[i];
            }
        }else{
            for(int i=0,j=m*var_num;i<var_num||j<(m+1)*var_num;i++,j++){
                permu_var[j]=b[i];
            }
        }
        m++;
	}else{
		b[k] = True;
		ExpVarPermutation(b,var_num,k+1,permu_var);
		b[k] = False;
		ExpVarPermutation(b,var_num,k+1,permu_var);
	}
}

//将输入的表达式转化为后缀表达式
void Transform(char* expression,Sqstack* s){
    int i=0;
    Sqstack optr;                          //存储逻辑符号的栈
    Sqstack output_stack;                  //最终转化为后缀表达式的栈
    InitStack(&optr);
    InitStack(&output_stack);
    char temp_char;
    char ch=expression[i];
    for(int i=0;expression[i]!='#';i++){
        ch=expression[i];
        if(ch>='A'&&ch<='Z')
            PushElem(&output_stack,ch);
        else{
            switch(ch){
            case '~':PushElem(&optr,ch); break;
            case '|':
                while(GetTopElem(optr)=='~'||GetTopElem(optr)=='&'){
                    PopElem(&optr,&temp_char);
                    PushElem(&output_stack,temp_char);
                }
                PushElem(&optr,ch);
                break;
            case '&':
                while(GetTopElem(optr)=='~'){
                    PopElem(&optr,&temp_char);
                    PushElem(&output_stack,temp_char);
                }
                PushElem(&optr,ch);
                break;
            case '(':PushElem(&optr,ch); break;
            case ')':
                while(GetTopElem(optr)!='('){
                    PopElem(&optr,&temp_char);
                    PushElem(&output_stack,temp_char);
                }
                PopElem(&optr,&temp_char);
                break;
            }
        }
    }
    while(!IsEmpty(optr)){
        PopElem(&optr,&temp_char);
        PushElem(&output_stack,temp_char);
    }
    while(!IsEmpty(output_stack)){
        PopElem(&output_stack,&temp_char);
        PushElem(s,temp_char);
    }
}

void UserOper(int num,BiTree& T){
    printf("用户输入逻辑变量值（变量之间中间用空格隔开）：");
    int elem_var[MAX_CHAR_NUM];
    InputElemVarible(elem_var,num);
    GiveValue(T,elem_var,num,0);
    PartCalculate(T);
    printf("表达式值为：%d\n",PartCalculate(T));
}

void TautologyChecker(){
    printf("\n请输入逻辑表达式：");
    char expression[MAX_CHAR_NUM];       //存储逻辑表达式
    char exp_var[MAX_CHAR_NUM]={0};
    int exp_num=0;                       //逻辑表达式长度
    int permu_var[MAX_NUM_PERMUT]={0};   //布尔值全排列
    Boolean b[mk];                       //单次排列的布尔值存储
    exp_num=InputExp(expression,exp_num);//输入表达式
    Sqstack exp_stack;                   //表达式栈
    InitStack(&exp_stack);
    Transform(expression,&exp_stack);    //将表达式入栈
    BiTree T;
    InitBiTree(T);
    CreateBiTree(&exp_stack,T);          //构造表达式二叉树
    PostOrderTraverse(T,exp_var);
    DiffVar(exp_var);
    ExpVarPermutation(b,mk,0,permu_var); //表达式逻辑变量赋值
    printf("\n");
    if(Calculate(T,permu_var,mk)==1)     //计算表达式结果
        printf("True Forever\n");
    else if(Calculate(T,permu_var,mk)==0)
        printf("False Forever\n");
    else{
        printf("Satisfactible\n");
        printf("\n");
        UserOper(mk,T);                  //可满足式的用户交互
    }
    printf("\n");
    fflush(stdin);
}


#endif // _OPERATE_H_
