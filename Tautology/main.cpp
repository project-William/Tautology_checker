#include "introduction.h"
#include "operate.h"
#include "userDefine.h"


int main(){
    Introduction();
    char ch;
    while(1){
        printf("�Ƿ��������ʽ�б�����(Y|N)��");
        scanf("%c",&ch);
        getchar();
        if(ch=='N') break;
        else TautologyChecker();

    }
    return 0;
}
