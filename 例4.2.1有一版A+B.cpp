#include<stdio.h>
int main(){
	long long a;
	long long b;
	int m;
	while(scanf("%d",&m)!=EOF){
		if(m==0) break;
		scanf("%lld %lld",&a,&b);
		long long c=a+b;
		int num[200];
		int i=0;
//		while(c>0){
//			num[i++]=c%m;
//			c=c/m;
//		}
		do{//����ִ��һ��ѭ��������0Ҳִ��һ�� 
			num[i++]=c%m;
			c=c/m;	
		}while(c>0);
		i--;
		for(int j=i;j>=0;j--){
			printf("%d",num[j]);
		} 
		
	}
	return 0;
}
