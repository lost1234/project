#include <stdio.h> 
#include <string.h> 

int main(int argc, char** argv) {
    FILE *fp = fopen(argv[1], "r") ;
    FILE *fp1 = fopen(argv[2], "w") ;
    if(fp == NULL || fp1 == NULL) {
        fprintf(stderr, "%s: failed to open \n", fp == NULL ? argv[1] : argv[2]) ;
    }

    char p1[255] ; 
    while(fgets(p1, sizeof(p1), fp)) {
        char *token = strtok(p1, " ") ;
        while(token) {
            if(strcmp(token, argv[3]) == 0) {
                fprintf(fp1, "%s", argv[4]) ;
            }
            else {
                fprintf(fp1, "%s", token) ;
            }
            if(token[strlen(token) - 1] != '\n') {
                fprintf(fp1, "%s", " ") ;
            }
            token = strtok(NULL, " ") ;
        }
    }
    fclose(fp) ;
    fclose(fp1) ;

    return 0 ;
}