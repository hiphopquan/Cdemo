#include<stdio.h>
int main(){
	int a;
	int b;
	int ra;
	int rb;
	while(scanf("%d",&a)!=EOF){
		b=a*a;
		for(int i=0;a>0;i++){
			ra=a%10;
			rb=b%10;
			a=a/10;
			b=b/10;
			if(ra==rb){
				
			}else{
				printf("No!\n");
				return 0;
			}	
		}
		printf("Yes!");
	}
	return 0; 
}
