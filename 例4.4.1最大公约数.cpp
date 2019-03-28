#include<stdio.h>
void cal(int a,int b){
	if(a==0&&b!=0){
		printf("%d",b);
	}
	if(a!=0&&b==0){
		printf("%d",a);
	}
	if(a!=0&&b!=0){
		cal(b,a%b);
	}
}
int main(){
	int a,b;
//	while(scanf("%d%d",&a,&b)!=EOF){
//		cal(a,b);
//		
//	} 
	a=0;
	b=3;
	printf("%d",a%b);
	return 0;
} 
