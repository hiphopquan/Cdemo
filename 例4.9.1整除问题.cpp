#include<stdio.h>
#include<math.h>
#include<limits.h>
//��a��n!�ֽ�������������a����������n!����С����С��ָ��
int inz[30];//�������� 
int inzm[30];
int inzind;
int su[1000];//������� 
int index;
int suind[1001];
void judge(){//�ҳ�1000������������ 
	for(int i=2;i<=1000;i++){
		if(suind[i]!=1){//�жϲ��Ƿ����� 
			su[index]=i;
			index++;
			int j=i*i;
			while(j<=1000){
				suind[j]=1;
				j=j+i;
			}
		}
	}
}
void cal(int n){//��n�ֽ������� 
	for(int i=0;i<index;i++){
		if(n%su[i]==0){
			inz[inzind]=su[i];
			inzm[inzind]=0;
			while(n%su[i]==0){
				inzm[inzind]++;
				n=n/su[i];
			}
			inzind++;	
		}
		if(n==1) break;
	} 
	if(n!=1){
		inz[inzind]=n;
		inzm[inzind]=1;
		inzind++;
	}
} 
int ninzm[30];
int main(){
	int n;
	int a;
	judge();
	while(scanf("%d%d",&n,&a)!=EOF){
		cal(a);
		int ans=22222222;
		for(int i=0;i<inzind;i++){
			if(n/inz[i]>0){
				int tmp=inz[i];
				while(n/tmp>0){
					ninzm[i]+=(n/tmp);
					tmp=tmp*inz[i];
				}
			}
			if(ninzm[i]/inzm[i]<ans){
				ans=ninzm[i]/inzm[i];
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
