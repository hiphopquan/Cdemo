#include<stdio.h>
#include<algorithm>
#include<string.h> 
using namespace std;
struct stu{
	char no[20];
	char name[10];
	char sex[5];
	int age;
}a[1000];
bool cmp(stu a,stu b){
	int stm=strcmp(a.no,b.no);
	return stm<0;
}
char num[10000][20];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s %s %s %d",a[i].no,a[i].name,a[i].sex,&a[i].age);
		} 
		int m;
		scanf("%d",&m);
		getchar();
		for(int i=0;i<m;i++){
			scanf("%s",num[i]);
			getchar();
		}
		sort(a,a+n,cmp);
//		for(int i=0;i<n;i++){
//			printf("%s %s %s %d\n",a[i].no,a[i].name,a[i].sex,a[i].age);
//		}
		printf("\n----------------------------\n");
		int k=0;

		while(k<m){
			
			int mid,r=n-1,l=0,ans=-1;
			mid=(r+l)/2;
			while(l<=r){
				int tmp=strcmp(a[mid].no,num[k]);
				if(!tmp){
					printf("%s %s %s %d\n",a[mid].no,a[mid].name,a[mid].sex,a[mid].age);
					ans=mid;
					break;
				}	
				else if(tmp>0)
					r=mid-1;
				else
					l=mid+1;
				mid=(r+l)/2;
			}
			if(ans==-1){
				printf("No Answer!\n");
			}
			
			k++;
		}
	}
	return 0;
}
