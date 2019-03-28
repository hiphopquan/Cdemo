#include<stdio.h>
struct bigint{
	int num[1000];
	int size;
	
	void init(){
		size=0;
		for(int i=0;i<1000;i++){
			num[i]=0; 
		}
	}
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1) printf("%04d",num[i]);
			else printf("%d",num[i]);
		}
		printf("\n");
	}
}ans;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0||n==1){
			printf("1\n");
		}else{
			ans.init();
			ans.num[ans.size]=1;
			ans.size++;
			int c;
			for(int i=2;i<=n;i++){
				c=0;
				for(int j=0;j<ans.size;j++){
					int tmp=ans.num[j]*i+c;
					ans.num[j]=tmp%10000;
					c=tmp/10000;
				}
				if(c!=0){
					ans.num[ans.size++]=c;
				}
			}
			ans.output();
		}
		
	}
	return 0;
}
