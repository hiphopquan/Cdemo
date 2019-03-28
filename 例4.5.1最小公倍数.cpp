#include<stdio.h>
int cal(int a,int b){
	if(b==0){
		return a;
	}else{
		return cal(b,a%b);
	}
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int c=cal(a,b);
		printf("%d\n",a*b/c);
	}
	return 0;
	
}
