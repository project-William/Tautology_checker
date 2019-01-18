#include "introduction.h"
#include "operate.h"
#include "userDefine.h"


int main(){
    Introduction();
    char ch;
    while(1){
        printf("是否进行重言式判别试验(Y|N)？");
        scanf("%c",&ch);
        getchar();
        if(ch=='N') break;
        else TautologyChecker();

    }
    return 0;
}
