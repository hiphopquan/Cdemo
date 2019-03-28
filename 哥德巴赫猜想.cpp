#include<stdio.h>
int num[1000];
int index=0;
int ans[1001];
void judge(){
	for(int i=2;i<1001;i++){
		if(ans[i]!=1){//没有被标记为非素数 
			num[index]=i;
			index++;
			int j=i*i;
			while(j<1001){
				ans[j]=1;//倍数标记为非素数
				j+=i; 
			} 
		}
	}
} 
int main(){
	int n;
	judge();
	int count=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<index;i++){
			for(int j=0;j<index;j++){
				if(num[i]+num[j]==n){
					printf("%d %d\n",num[i],num[j]);
					count++;
				}else if(num[i]+num[j]>n){
					break;
				}
			}
			if(count>0){
				break;
			}
		}
		count=0;
	}
	return 0;
}
