#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct bigint{
	int num[100];
	int size;
	
	void init(){
		for(int i=0;i<100;i++)
			num[i]=0;
		size=0;
	}
	
	void set(char *s){
		init();
		int l=strlen(s);
		for(int i=l-1,j=0,t=0,c=1;i>=0;i--)
		{
			t+=(s[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0)
			{
				num[size++]=t;
				j=0;
				t=0;
				c=1;
			}
		}
	}
	
	bigint operator + (const bigint &a) const{
		bigint ret;
		ret.init();
		int c=0;
		for(int i=0;i<a.size||i<size;i++){
			int tmp=num[i]+a.num[i]+c;
			ret.num[ret.size++]=tmp%10000;
			c=tmp/10000;
		}
		if(c!=0) ret.num[ret.size++]=c;
		return ret;
	}
	
	bigint operator * (int x) const{
		bigint ret;
		ret.init();
		int c=0;
		for(int i=0;i<size;i++){
			int tmp=num[i]*x+c;
			ret.num[ret.size++]=tmp%10000;
			c=tmp/10000;
		}
		if(c!=0) ret.num[ret.size++]=c;
		return ret;
	}
	
	bool operator < (const bigint &a) const{
		if(size!=a.size){
			return size<a.size;
		}else{
			for(int i=size-1;i>=0;i--){
				if(num[i]!=a.num[i])
					return num[i]<a.num[i];
			}
		}
	} 
	
	int operator % (int x) const{
		int r=0;
		for(int i=size-1;i>=0;i--){
			int t=num[i]+r*10000;
			r=t%x;
		}
		return r;
	}
	
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1) printf("%04d",num[i]);
			else printf("%d",num[i]);
		}
		printf("\n");
	}
	
};
struct E{
	int next;
	bigint v;
}; 
bigint Dis[100];
bool flag[100];
bool mark[100];
vector<E> edge[100];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			edge[i].clear();
			mark[i]=false;
			flag[i]=false;
		}
		bigint k;
		k.set("1");
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);	
			E tmp;
			tmp.next=b;
			tmp.v=k;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
			k=k*2;
		}
		Dis[0].set("0");
		mark[0]=true;
		flag[0]=true;
		int newP=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next;
				bigint c=edge[newP][j].v;
				if(mark[t]==true) continue;
				if(flag[t]==false||(Dis[newP]+c)<Dis[t]){
					Dis[t]=Dis[newP]+c;
					flag[t]=true; 
				}
			}
			bigint min;
			min.set("9999999999999999999999999999");
			for(int j=1;j<n;j++){
				if(flag[j]==false) continue;
				if(mark[j]==true) continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;

		}
		for(int i=1;i<n;i++){
			if(flag[i]==false){
				printf("-1\n");
			}else{
				printf("%d\n",Dis[i]%100000);
			}
		}	
	}
	return 0;
}
