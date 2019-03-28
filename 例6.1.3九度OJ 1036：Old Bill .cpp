#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int x,y,z;
		int max=0;
		int indi=0,indj=0;
		scanf("%d %d %d",&x,&y,&z);
		int m=x*1000+y*100+z*10;
		for(int i=1;i<=9;i++){
			int p=i*10000+m;
			for(int j=0;j<=9;j++){
				int q=0;
				q=p+j;
				if(q%n==0){
					max=q;
					indi=i;
					indj=j;
				}
			}
		}
		if(max==0) printf("0\n");
		else printf("%d %d %d\n",indi,indj,max/n);
	}
	return 0;
} 
