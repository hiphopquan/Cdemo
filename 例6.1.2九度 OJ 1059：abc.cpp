#include<stdio.h>
int main(){
	for(int a=0;a<=9;a++){
		for(int b=0;b<=9;b++){
			for(int c=0;c<=9;c++){
				int x=a*100+b*10+c;
				int y=b*100+c*10+c;
				if(x+y==532){
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
} 
