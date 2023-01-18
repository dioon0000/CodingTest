#include <stdio.h>

int main() {
    int i,a,b,c,d,temp,flag=1;
    int arr[10050]={0,};
    for(i=1; i<=10000; i++){
        if(i>=1000){
            a=i/1000;
            b=i/100%10;
            c=i%100/10;
            d=i%10;
            temp =i+a+b+c+d;
            arr[temp-1]=flag;
        }
        else if(i>=100){
            a=i/100;
            b=(i%100)/10;
            c=i%10;
            temp = i+a+b+c;
            arr[temp-1]=flag;
        }
        else if(i>=10){
            a=i/10;
            b=i%10;
            temp = i+a+b;
            arr[temp-1]=flag;
        }
        else if(i>=1){
            temp = i+i;
            arr[temp-1]=flag;
        }
        if(arr[i-1]==0){
            printf("%d\n",i);
        }
    }
    return 0;
}