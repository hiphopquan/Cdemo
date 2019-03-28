#include<stdio.h>
int ans[10001];//默认初始化为全0 全部没标记 
int main(){
	int n;
	int count=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=2;i<n;i++){
			if(ans[i]!=1){//没有被标记为非素数就是素数 1代表非素数 
				if(i%10==1){//个位数为1 才输出，但所有素数都标记后续数 
					count++;
					if(count==1){
						printf("%d",i);
						
					}else{
						printf(" %d",i);
					}	
				}
				int j=i;
				j=j+i;//可以从i*i开始因为i*k(k<i)也是k的素因数 
				while(j<n){
					ans[j]=1;//倍数标记为非素数 
					j=j+i;
				} 	 
			}
			//素数不采取操作 
		}
		if(count==0){
			printf("-1\n");
		}else{
			printf("\n");
		} 
	}
} 
