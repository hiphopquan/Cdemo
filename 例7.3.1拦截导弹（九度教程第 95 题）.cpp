#include<stdio.h>
int main(){
	int k;
	int h[30];
	int num[30];
	while(scanf("%d",&k)!=EOF){
		for(int i=1;i<=k;i++){
			scanf("%d",&h[i]);
		}
		//Ѱ����ݼ�������
		num[1]=1;//num[i]��ʾ��h[i]��β����ݼ������г���
		int cnt=num[1];
		for(int i=2;i<=k;i++){
			int max=1;//��С��1����ûһ��������С��h[i] 
			for(int j=1;j<i;j++){
				if(h[j]>=h[i]){
					if(num[j]+1>max)
						max=num[j]+1;
				}
			}
			num[i]=max;
			if(num[i]>cnt)
				cnt=num[i];
		} 
		printf("%d\n",cnt);
	}
}
