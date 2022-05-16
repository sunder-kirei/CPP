#include <stdio.h>
#include <string.h>

void main(){
    int n;
    scanf("%d", &n);
    char s1[1];
    sprintf(s1,"%d",n);

    int i = 0, str = (strlen(s1)-1);
    
    while(i < (str)/2){
        if(s1[i] != s1[str-i]){
            printf("Not a Palindrome \n");
            return;
        }
        
        i++;
    }
    printf("Palindrome");
    return;
}