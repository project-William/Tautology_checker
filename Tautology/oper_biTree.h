#ifndef _OPER_BITREE_H_
#define _OPER_BITREE_H_
#include "userDefine.h"
#include "elem_stack.h"
#include <stdio.h>
int mk=0;

typedef struct Node{
    char elem;
    int value;
    struct Node* left_child;
    struct Node* right_child;
}*BiTree,BiTreeNode;
//二叉树模块函数
void InitBiTree(BiTree& T);               //初始化一个树头结点
void CreateBiTree(Sqstack *s,BiTree& T);  //通过后缀表达式进行表达式二叉树构建
void PostOrderTraverse(BiTree& T);        //后序遍历二叉树




void InitBiTree(BiTree& T){
    T=(BiTree)malloc(sizeof(BiTreeNode));
    T->left_child=NULL;
    T->right_child=NULL;
}

void CreateBiTree(Sqstack *s,BiTree& T){
    typedef struct BiNode{
        BiTreeNode* binode_pointer[MAX_BITREE_NODE];
        int top;
    }Bistack;
    Bistack *bi_stack;
    bi_stack=(Bistack*)malloc(sizeof(Bistack));
    BiTreeNode* new_node;
    bi_stack->top=-1;
    char x;
    while(!IsEmpty(*s)){
        PopElem(s,&x);
        if(x!='~'&&x!='|'&&x!='&'){
            new_node=(BiTreeNode*)malloc(sizeof(BiTreeNode));
            new_node->elem=x;
            new_node->left_child=NULL;
            new_node->right_child=NULL;
            bi_stack->binode_pointer[++bi_stack->top]=new_node;
        }else if(x=='~'){
            new_node=(BiTreeNode*)malloc(sizeof(BiTreeNode));
            new_node->elem=x;
            new_node->left_child=NULL;
            new_node->right_child=bi_stack->binode_pointer[bi_stack->top--];
            bi_stack->binode_pointer[++bi_stack->top]=new_node;
        }else if(x=='|'||x=='&'){
            new_node=(BiTreeNode*)malloc(sizeof(BiTreeNode));
            new_node->elem=x;
            new_node->left_child=bi_stack->binode_pointer[bi_stack->top--];
            new_node->right_child=bi_stack->binode_pointer[bi_stack->top--];
            bi_stack->binode_pointer[++bi_stack->top]=new_node;
        }
    }
    T=new_node;
}

void PostOrderTraverse(BiTree& T,char* exp_var){
    if(!T)
        return;
    else{
        PostOrderTraverse(T->left_child,exp_var);
        PostOrderTraverse(T->right_child,exp_var);
        if(T->elem<='Z'&&T->elem>='A')
            exp_var[mk++]=T->elem;
    }
}

void DiffVar(char*exp_var){
    int i,j,k;
    for(i=0;i<=mk-1;i++){
        for(j=i+1;j<=mk-1;j++){
            if(exp_var[i] == exp_var[j]){
                 for(k = j;k <= mk - 1;k ++){
                    exp_var[k]=exp_var[k + 1];
                 }
                 mk --;
                 j --;
            }
        }
    }
}

void GiveValue(BiTree& T,int* permu_var,int num,int nk){
    if(!T)
        return;
    GiveValue(T->left_child,permu_var,num,nk);
    GiveValue(T->right_child,permu_var,num,nk);
    if(T->elem>='A'&&T->elem<='Z'){
        T->value=permu_var[T->elem-65+nk*2];
    }
}

int PartCalculate(BiTree& T){
    BiTree p=T;
    if(!p)
        return 0;
    if(p->left_child) PartCalculate(p->left_child);
    if(p->right_child) PartCalculate(p->right_child);
    if(p->elem>='A'&&T->elem<='Z'){
        printf("");
    }else if(p->elem=='|'){
        if(p->left_child->value==0&&p->right_child->value==0)
            p->value=0;
        else p->value=1;
    }else if(p->elem=='&'){
        if(p->left_child->value==1&&p->right_child->value==1)
            p->value=1;
        else p->value=0;
    }else if(p->elem=='~'){
        if(p->right_child->value==0)
            p->value=1;
        else p->value=0;
    }
    return p->value;
}


int Calculate(BiTree T,int* permu_var,int num){
    int result[MAX_CHAR_NUM];
    int solution_T=0;
    int solution_F=0;
    BiTree p=T;
    for(int i=0;i<pow(2,num);i++){
        GiveValue(p,permu_var,2,i);
        result[i]=PartCalculate(T);
        p=T;
    }
    for(int i=0;i<pow(2,num);i++){
        if(result[i]==1)
            solution_T++;
        else solution_F++;
    }
    if(solution_T==pow(2,num))
        return 1;
    if(solution_F==pow(2,num))
        return 0;
    else return -1;
}




#endif // _OPER_BITREE_H_
