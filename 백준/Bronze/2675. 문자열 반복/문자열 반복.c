#include <stdio.h>
#include <string.h>
int main(){
    int t, r, i, j, k, len;
    char arr[21]={0,};
    
    scanf("%d",&t);
    for(i=0; i<t; i++){
        scanf("%d",&r);
        scanf("%s",arr);
        for(j=0; j<strlen(arr); j++){
            for(k=0; k<r; k++){
                printf("%c",arr[j]);
            }
        }
        printf("\n");
    }
    return 0;
}