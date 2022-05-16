#include <stdio.h>
#include <string.h>

int main(){
    // int i, arr[5] ;
    // for(int i = 0; i<5; i++){
    //     scanf("%d", &arr[i]) ;
    // }
    // for(int i = 0; i<5; i++){
    //     printf("%d", arr[i]) ;
    // }
    // printf("%d", 'A');
    // return 0;

    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    strcat(s1,s2);
    printf("%s", s1);
    return 0;
}