#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int bound=sqrt(n)+1; //sqrt����ֵΪdouble��ֹdouble��ʧ���ȣ�+1��ö��һ��������ö�� 
	while(scanf("%",&n)!=EOF){
		for(int i=2;i<=bound;i++){//��bound�������sqrt()���������ʡ����ʱ�䣬sqrt()�����Ϊ��ʱ 
			if(n%i==0){
				printf("no");
				return 0;
			}
		}
		printf("yes");
		return 0;
	}
	return 0;
	
} 
