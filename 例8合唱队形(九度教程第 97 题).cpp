#include<stdio.h>
int main(){
	int n;
	int h[101];
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		int num1[101];
		int num2[101];
		num1[1]=1;
		num2[n]=1;
		for(int i=2;i<=n;i++){
			int max=1;
			for(int j=1;j<i;j++){
				if(h[j]<h[i])
					max=num1[j]+1;
			}
			num1[i]=max;
		}
		for(int i=n-1;i>=1;i--){
			int max=1;
			for(int j=n;j>i;j--){
				if(h[j]<h[i])
					max=num2[j]+1;
			}
			num2[i]=max;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((num1[i]+num2[i])>cnt)
				cnt=num1[i]+num2[i]-1;
		}
		printf("%d\n",n-cnt);
	}
	return 0;
}
