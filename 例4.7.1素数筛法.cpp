#include<stdio.h>
int ans[10001];//Ĭ�ϳ�ʼ��Ϊȫ0 ȫ��û��� 
int main(){
	int n;
	int count=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=2;i<n;i++){
			if(ans[i]!=1){//û�б����Ϊ�������������� 1��������� 
				if(i%10==1){//��λ��Ϊ1 ���������������������Ǻ����� 
					count++;
					if(count==1){
						printf("%d",i);
						
					}else{
						printf(" %d",i);
					}	
				}
				int j=i;
				j=j+i;//���Դ�i*i��ʼ��Ϊi*k(k<i)Ҳ��k�������� 
				while(j<n){
					ans[j]=1;//�������Ϊ������ 
					j=j+i;
				} 	 
			}
			//��������ȡ���� 
		}
		if(count==0){
			printf("-1\n");
		}else{
			printf("\n");
		} 
	}
} 
