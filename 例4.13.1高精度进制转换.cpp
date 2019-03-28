#include<stdio.h>
#include<string.h>
#define maxSize 10
struct bigint{
	int num[maxSize];
	int size;
	
	void init(){
		for(int i=0;i<maxSize;i++) num[i]=0;
		size=0;
	}
	
	void set(int x){//普通整数----->>高精度整数 
		init();
		do{
			num[size++]=x%10000;
			x=x/10000;	
		}while(x!=0); 
	}
	
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1) printf("%04d",num[i]);
			else printf("%d",num[i]);
		}
		printf("\n");
	}
	
	bigint operator * (int x) const{//高精度数与普通整数乘积 
		bigint ret;
		ret.init(); 
		int c=0;
		for(int i=0;i<size;i++){
			int t=num[i]*x+c;
			ret.num[ret.size++]=t%10000;
			c=t/10000;
		}
		if(c!=0){
			ret.num[ret.size++]=c;
		}
		return ret;
	}
	
	bigint operator + (const bigint &a) const{//高精度整数与高精度整数加法 
		bigint ret;
		ret.init();
		int c=0;
		for(int i=0;i<size||i<a.size;i++){
			int t=num[i]+a.num[i]+c;
			ret.num[ret.size++]=t%10000;
			c=t/10000;
		}
		if(c!=0){
			ret.num[ret.size++]=c;
		}
		return ret;
	}
	
	bigint operator / (int x) const{//高精度整数对普通整数求商 
		bigint ret;
		ret.init();
		int r=0;
		for(int i=size-1;i>=0;i--){
			int t=num[i]+r*10000;
			ret.num[i]=t/x;
			r=t%x;
		}
		ret.size=0;
		for(int i=0;i<maxSize;i++){
			if(ret.num[i]!=0)
				ret.size=i;
		} 
		ret.size++;
		return ret;
		
	} 
	
	int operator % (int x) const{//高精度整数对普通整数求余数 
		int r=0;
		for(int i=size-1;i>=0;i--){
			r=(num[i]+r*10000)%x;
		} 
		return r;
	}
	
}sum,mi;//十进制和   累加中间值   幂 

int main(){
	int m,n;
	char x[1000];
	char ans[1000];
	
	while(scanf("%d%d",&m,&n)!=EOF){
		scanf("%s",x); 
		int L=strlen(x);
		sum.set(0);//累加得到的十进制值 
		mi.set(1);
		for(int i=L-1;i>=0;i--){
			int t;
			if(x[i]>='0'&&x[i]<='9') t=x[i]-'0';
			else t=x[i]-'A'+10;
			sum=sum+mi*t;
			mi=mi*m; 
		} 
		int size=0;
		do{
			int t=sum%n;
			if(t>=10) ans[size++]=t-10+'a';
			else ans[size++]=t+'0';
			sum=sum/n;
		}while(!(sum.num[0]==0&&sum.size==1));
		for(int i=size-1;i>=0;i--){
			printf("%c",ans[i]);
		} 
		printf("\n");
	}
	return 0;
}
