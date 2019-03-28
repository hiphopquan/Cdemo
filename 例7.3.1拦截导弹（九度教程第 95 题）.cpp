#include<stdio.h>
int main(){
	int k;
	int h[30];
	int num[30];
	while(scanf("%d",&k)!=EOF){
		for(int i=1;i<=k;i++){
			scanf("%d",&h[i]);
		}
		//寻找最长递减子序列
		num[1]=1;//num[i]表示以h[i]结尾的最长递减子序列长度
		int cnt=num[1];
		for(int i=2;i<=k;i++){
			int max=1;//最小是1，即没一个数均比小于h[i] 
			for(int j=1;j<i;j++){
				if(h[j]>=h[i]){
					if(num[j]+1>max)
						max=num[j]+1;
				}
			}
			num[i]=max;
			if(num[i]>cnt)
				cnt=num[i];
		} 
		printf("%d\n",cnt);
	}
}
