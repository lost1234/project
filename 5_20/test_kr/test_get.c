#include <stdio.h>
#include <stdlib.h> 
/* 
fgets() 函数会读取换行符，读取结束后，fgets函数会为buf在末尾添加一个空字符作为字符串的结束。
*/
#define LEN 6 
int main(int argc, char* argv[])
{
    char src[LEN] ;
    printf("please enter: \n") ;
    fgets(src, LEN, stdin) ;
    printf("you enter is: \n") ;
    fputs(src, stdout) ;
}