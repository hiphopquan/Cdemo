#include<stdio.h>
int main(){
	int h,i;
	scanf("%d",&h);
	for(i=0;i<h;i++){
		for(int j=0;j<2*(h-i-1);j++){
			printf(" ");
		}
		for(int k=0;k<h+2*i;k++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
