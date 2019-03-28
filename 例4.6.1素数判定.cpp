#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int bound=sqrt(n)+1; //sqrt返回值为double防止double损失精度，+1多枚举一个而不少枚举 
	while(scanf("%",&n)!=EOF){
		for(int i=2;i<=bound;i++){//用bound代替减少sqrt()计算次数节省运算时间，sqrt()运算较为耗时 
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
