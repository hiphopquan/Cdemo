#include<stdio.h>
int a[100][100];
int count[100]; 
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				a[i][j]=0;//Ĭ�ϲ����ڹ��� 
			}
			count[i]=0;
		}
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=1;
			count[y]++;
		} 
		int k=0;
		int s=n;
		while(s-->0){//n������ 
			for(int i=0;i<n;i++){//�������Ϊ0�� 
				if(count[i]==0){//û��ǰ����ѡ�в�ȥ������������� 
					k++;
					for(int j=0;j<n;j++){
						if(a[i][j]==1){
							a[i][j]=0;
							int y=j;
							count[y]--;
						}
					}
					count[i]=-1;//��ʾ�õ��Ѿ�ȥ�� 
				} 
			}	
		} 
		if(k==n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}	
	}
	return 0;
} 
