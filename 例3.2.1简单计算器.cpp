#include<stdio.h>
#include<stack> 
using namespace std;
char flag[5]={'#','+','-','*','/'};//��������� 
int pr[5]={0,1,1,2,2};//�������Ӧ���ȼ� 
stack<double> num;//����ջ
stack<int> ind;//������±�ջ 
char str[220]; 
void next(char *str){
	ind.push(0);//Ԥ��ֲ��������ȼ��±�
	int i=0;
	for(;str[i]!=0;i++){
		double tmp=0;
		if(str[i]>='0'&&str[i]<='9'){
			tmp=tmp*10+(str[i]-'0');
			i++;
			while(str[i]!=0&&str[i]!=' '){
				tmp=tmp*10+(str[i]-'0');
				i++;	
			}
			num.push(tmp);
			if(str[i]==0){
				while(ind.top()!=0){
					double x,y;
					y=num.top();//�ڶ�����
					num.pop(); 
					x=num.top();//��һ���� 
					num.pop(); 
					int opind=ind.top();
					ind.pop();
					if(opind==1) x=x+y; 
					if(opind==2) x=x-y; 
					if(opind==3) x=x*y; 
					if(opind==4) x=x/y; 
					num.push(x);
				}
				break;	
			}
			
		}else{
			if(str[i]=='+'){
				while(1){
					if(pr[ind.top()]<1){//ջ����������ȼ�С�ڵ�ǰ��������������ջ 
						ind.push(1);
						break;	
					}else{//ջ����������ڵ��ڵ�ǰ�������ջ���������ջ���������� 
						double x,y;
						y=num.top();//�ڶ�����
						num.pop(); 
						x=num.top();//��һ���� 
						num.pop(); 
						int opind=ind.top();
						ind.pop();
						if(opind==1) x=x+y; 
						if(opind==2) x=x-y; 
						if(opind==3) x=x*y; 
						if(opind==4) x=x/y; 
						num.push(x);
					}	
				}
				
				
				
			}	
			if(str[i]=='-'){
				while(1){
					if(pr[ind.top()]<1){//ջ����������ȼ�С�ڵ�ǰ��������������ջ 
						ind.push(2);
						break;	
					}else{//ջ����������ڵ��ڵ�ǰ�������ջ���������ջ���������� 
						double x,y;
						y=num.top();//�ڶ�����
						num.pop(); 
						x=num.top();//��һ���� 
						num.pop(); 
						int opind=ind.top();
						ind.pop();
						if(opind==1) x=x+y; 
						if(opind==2) x=x-y; 
						if(opind==3) x=x*y; 
						if(opind==4) x=x/y; 
						num.push(x);
					}	
				}
				
				
				
			}	 
			if(str[i]=='*'){
				while(1){
					if(pr[ind.top()]<2){//ջ����������ȼ�С�ڵ�ǰ��������������ջ 
						ind.push(3);
						break;	
					}else{//ջ����������ڵ��ڵ�ǰ�������ջ���������ջ���������� 
						double x,y;
						y=num.top();//�ڶ�����
						num.pop(); 
						x=num.top();//��һ���� 
						num.pop(); 
						int opind=ind.top();
						ind.pop();
						if(opind==1) x=x+y; 
						if(opind==2) x=x-y; 
						if(opind==3) x=x*y; 
						if(opind==4) x=x/y; 
						num.push(x);
					}	
				}
				
				
				
			} 
			if(str[i]=='/'){
				while(1){
					if(pr[ind.top()]<2){//ջ����������ȼ�С�ڵ�ǰ��������������ջ 
						ind.push(4);
						break;	
					}else{//ջ����������ڵ��ڵ�ǰ�������ջ���������ջ���������� 
						double x,y;
						y=num.top();//�ڶ�����
						num.pop(); 
						x=num.top();//��һ���� 
						num.pop();
						int opind=ind.top();
						ind.pop();
						if(opind==1) x=x+y; 
						if(opind==2) x=x-y; 
						if(opind==3) x=x*y; 
						if(opind==4) x=x/y; 
						num.push(x);
					}	
				}	
			} 
			i++;
		}		
	
	}
} 
int main(){
	gets(str);
	next(str);
	
	while(num.empty()==false){
		printf("%.2f\n",num.top());
		num.pop();
	}
//	while(ind.empty()==false){
//		printf("%c",flag[ind.top()]);
//		ind.pop();
//	}
	//puts(str);
	return 0; 
} 
