#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(float i=0;i<=n/5;i++){
			for(float j=0;j<=n/3;j++){
				/*for(float k=0;k<=n*3;k++){
					if((i+k+j)==100&&(i*5+j*3+k/3)<=n){
						int ii=(int)i;
						int ij=(int)j;
						int ik=(int)k;
						printf("x=%d,y=%d,z=%d\n",ii,ij,ik);
					}
				}*/
				float k=100-i-j;
				if((i*5+j*3+k/3)<=n){//为避免int精度损失可以采用等式两遍同乘3的方法 
					int ii=(int)i;
					int ij=(int)j;
					int ik=(int)k;
					printf("x=%d,y=%d,z=%d\n",ii,ij,ik);
				} 
			}
		}
	}
}
