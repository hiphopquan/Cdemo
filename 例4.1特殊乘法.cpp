#include<stdio.h>
int main(){
	int a;
	int b;
	int cb;
	int ra;
	int rb;
	int sum=0;
	while(scanf("%d",&a)!=EOF){
		
		scanf("%d",&b); 
		
		while(a>0){
			ra=a%10;
			a=a/10;
			cb=b;
			while(cb>0){
				rb=cb%10;
				cb=cb/10;
//				printf("%d*%d\n",ra,rb);
				sum=sum+ra*rb;
			}
			
		}
		printf("%d\n",sum);	
	}
	return 0;
	
} 
