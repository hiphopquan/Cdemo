#include<stdio.h>
int main(){
    int n,a[30],r,i;
    for(i=0;i<30;i++){
        a[i]=0;
    }
    scanf("%d",&n);
    if(n==0){
        printf("0");
    }
    else if(n>0&&n<=10^8){
    	i=0;
    	r=n%2;
        n=n/2;
        a[i]=r;
        while(n!=0){
            r=n%2;
            n=n/2;
            a[++i]=r;
        }
        for(i=29;i>=0&&a[i]==0;i--){}
        for(;i>=0;i--){
            printf("%d",a[i]);
        }
    }else{
        printf("ÊäÈë´íÎó");
    }
    return 0; 
}
