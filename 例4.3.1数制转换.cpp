#include<stdio.h>
#include<math.h>
int main(){
	long a;
	char num[70];
	long b;
	while(scanf("%ld",&a)!=EOF){
		scanf("%s",num);
		
		scanf("%ld",&b);
		int v[70];
		int i;
		for(i=0;num[i]!=0;i++){
			if(num[i]>='0'&&num[i]<='9'){
				v[i]=num[i]-'0';
			}else if(num[i]=='a'||num[i]=='A'){
				v[i]=10;
			}else if(num[i]=='b'||num[i]=='B'){
				v[i]=11;
			}else if(num[i]=='c'||num[i]=='C'){
				v[i]=12;
			}else if(num[i]=='d'||num[i]=='D'){
				v[i]=13;
			}else if(num[i]=='e'||num[i]=='E'){
				v[i]=14;
			}else if(num[i]=='f'||num[i]=='F'){
				v[i]=15;
			}
		}
		--i;
		int ten=0;//十进制值 
		for(int j=0;j<=i;j++){
			int m=pow(a,(i-j));
//			printf("%d",m);
//			printf("%d\n",v[j]*m);//v[j]*pow(i-j)和v[j]*a^(i-j)都是错误的写法 
			ten=ten+v[j]*pow(a,(i-j));
		}
//		printf("%d",ten);
		int vb[70];//b进制数 
		int r=0;
		int k=0;
		do{
			r=ten%b;
			ten=ten/b;
			vb[k++]=r;
		}while(ten>0); 
		k--;
		for(int j=k;j>=0;j--){
			if(vb[j]==10){
				printf("A");
			}else if(vb[j]==11){
				printf("B");
			}else if(vb[j]==12){
				printf("C");
			}else if(vb[j]==13){
				printf("D");
			}else if(vb[j]==14){
				printf("E");
			}else if(vb[j]==15){
				printf("F");
			}else{
				printf("%d",vb[j]);
			}
		}
	}
	return 0;
} 
