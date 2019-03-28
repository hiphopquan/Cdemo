#include<stdio.h>
int main(){
	int n,a[1000],countj=0,counto=0;
	scanf("%d",&n);
	if(n<1||n>1000){
		printf("ÊäÈë´íÎó");
	}else{
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int j=0;j<n;j++){
			if(a[j]%2==0)
				counto++;	
		}
		countj=n-counto;
		if(counto>countj)
			printf("NO");
		else
			printf("YES");
	}
}
