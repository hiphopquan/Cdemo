#include<stdio.h>
int main(){
	int a,ca;
	int b,cb;
	int k;
	while(scanf("%d",&a)!=EOF){
		scanf("%d",&b);
		scanf("%d",&k);
		ca=a;
		cb=b;
		if(a==0&&b==0)
			break;
		for(int i=1;i<=k;i++){
			int ra,rb;
			ra=a%10;
			rb=b%10;
			a=a/10;
			b=b/10;
			if(ra==rb){
				
			}else{
				printf("%d\n",ca+cb);
				return 0;
			}
		}
		printf("-1\n");
		return 0;
	}
	
	return 0;

}
