#include<stdio.h>
int num[1000001]={0};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num[x+500000]++;
	}
	for(int i=1000000;i>=0&&m>0;i--){
		if(num[i]){
			if(m==1) 
				printf("%d\n",i-500000);
			else
				printf("%d ",i-500000);
			m--;	
		}	
		
	}
}
