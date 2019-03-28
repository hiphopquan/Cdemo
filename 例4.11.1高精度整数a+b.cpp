#include<stdio.h>
#include<string.h> 
#include<math.h>
struct bigint{
	int num[1001];
	int size;
};
int main(){
	char str1[1001],str2[1001];
	bigint p,q;
	while(scanf("%s %s",str1,str2)!=EOF){
		int L1,L2;
		L1=strlen(str1);
		L2=strlen(str2);
		p.size=0;
		q.size=0;
		for(int i=L1-1;i>=0;){
			int sum=0;
			for(int j=0;j<4&&i>=0;j++){
				sum=sum+(str1[i]-'0')*pow(10,j);
				i--;
			}
			p.num[p.size]=sum;
			p.size++;
		}
		for(int i=L2-1;i>=0;){
			int sum=0;
			for(int j=0;j<4&&i>=0;j++){
				sum=sum+(str2[i]-'0')*pow(10,j);
				i--;
			}
			q.num[q.size]=sum;
			q.size++;
		}
		bigint s;
		s.size=0;
		int j=0;
		for(;j<p.size||j<q.size;j++){
			s.num[j]=0;
		}
		for(j=0;j<p.size&&j<q.size;j++){
			int tmp=s.num[j]+p.num[j]+q.num[j];
			s.num[j]=tmp%10000;
			if(tmp/10000>0){
				s.num[j+1]+=1;
			}
			s.size++;
		}
		while(j<p.size){
			int tmp=s.num[j]+p.num[j];
			s.num[j]=tmp%10000;
			if(tmp/10000>0){
				s.num[j+1]+=1;
			}
			j++;
			s.size++;
		}
		while(j<q.size){
			int tmp=s.num[j]+q.num[j];
			s.num[j]=tmp%10000;
			if(tmp/10000>0){
				s.num[j+1]+=1;
			}
			j++;
			s.size++;
		}
		for(int i=s.size-1;i>=0;i--){
			if(i!=s.size-1) printf("%04d",s.num[i]);//用%04的输出前导0,即当前数字不足4位时由0补充
			else printf("%d",s.num[i]);	
		}
		printf("\n");	
	}
	return 0;
}
