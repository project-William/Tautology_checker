#ifndef _OPERATE_H_
#define _OPERATE_H_
#include <math.h>
#include "userDefine.h"
#include "oper_biTree.h"
#include "user.h"

int m=0;
enum Boolean{True,False};


//����ģ�麯��
void ExpressionVarible(char* expression,char* varibleList,int num);  //�����ʽ�е��߼���������洢�Ա����ȫ����ȡֵ
void Transform(char* expression,Sqstack* s);                         //���û�������߼����ʽת��Ϊ��׺���ʽ
void ExpVarPermutation(char* varible_list);                         //�߼�������ȫ����


//�����߼�������ȫ����
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

//������ı��ʽת��Ϊ��׺���ʽ
void Transform(char* expression,Sqstack* s){
    int i=0;
    Sqstack optr;                          //�洢�߼����ŵ�ջ
    Sqstack output_stack;                  //����ת��Ϊ��׺���ʽ��ջ
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
    printf("�û������߼�����ֵ������֮���м��ÿո��������");
    int elem_var[MAX_CHAR_NUM];
    InputElemVarible(elem_var,num);
    GiveValue(T,elem_var,num,0);
    PartCalculate(T);
    printf("���ʽֵΪ��%d\n",PartCalculate(T));
}

void TautologyChecker(){
    printf("\n�������߼����ʽ��");
    char expression[MAX_CHAR_NUM];       //�洢�߼����ʽ
    char exp_var[MAX_CHAR_NUM]={0};
    int exp_num=0;                       //�߼����ʽ����
    int permu_var[MAX_NUM_PERMUT]={0};   //����ֵȫ����
    Boolean b[mk];                       //�������еĲ���ֵ�洢
    exp_num=InputExp(expression,exp_num);//������ʽ
    Sqstack exp_stack;                   //���ʽջ
    InitStack(&exp_stack);
    Transform(expression,&exp_stack);    //�����ʽ��ջ
    BiTree T;
    InitBiTree(T);
    CreateBiTree(&exp_stack,T);          //������ʽ������
    PostOrderTraverse(T,exp_var);
    DiffVar(exp_var);
    ExpVarPermutation(b,mk,0,permu_var); //���ʽ�߼�������ֵ
    printf("\n");
    if(Calculate(T,permu_var,mk)==1)     //������ʽ���
        printf("True Forever\n");
    else if(Calculate(T,permu_var,mk)==0)
        printf("False Forever\n");
    else{
        printf("Satisfactible\n");
        printf("\n");
        UserOper(mk,T);                  //������ʽ���û�����
    }
    printf("\n");
    fflush(stdin);
}


#endif // _OPERATE_H_
