#include<stdio.h>
int main(){
	int n;
	int f[20];
	f[1]=1;
	f[2]=2;
	while(scanf("%d",&n)!=EOF){
		for(int i=3;i<=n;i++)
			f[i]=f[i-1]+f[i-2];
		printf("%d\n",f[n]); 
	} 
	return 0;
}
