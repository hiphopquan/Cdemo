#include<stdio.h>
#include<stack> 
using namespace std;
char flag[5]={'#','+','-','*','/'};//五种运算符 
int pr[5]={0,1,1,2,2};//运算符对应优先级 
stack<double> num;//数字栈
stack<int> ind;//运算符下标栈 
char str[220]; 
void next(char *str){
	ind.push(0);//预先植入最低优先级下标
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
					y=num.top();//第二个数
					num.pop(); 
					x=num.top();//第一个数 
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
					if(pr[ind.top()]<1){//栈顶运算符优先级小于当前运算符，运算符入栈 
						ind.push(1);
						break;	
					}else{//栈顶运算符大于等于当前运算符，栈顶运算符出栈，算术运算 
						double x,y;
						y=num.top();//第二个数
						num.pop(); 
						x=num.top();//第一个数 
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
					if(pr[ind.top()]<1){//栈顶运算符优先级小于当前运算符，运算符入栈 
						ind.push(2);
						break;	
					}else{//栈顶运算符大于等于当前运算符，栈顶运算符出栈，算术运算 
						double x,y;
						y=num.top();//第二个数
						num.pop(); 
						x=num.top();//第一个数 
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
					if(pr[ind.top()]<2){//栈顶运算符优先级小于当前运算符，运算符入栈 
						ind.push(3);
						break;	
					}else{//栈顶运算符大于等于当前运算符，栈顶运算符出栈，算术运算 
						double x,y;
						y=num.top();//第二个数
						num.pop(); 
						x=num.top();//第一个数 
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
					if(pr[ind.top()]<2){//栈顶运算符优先级小于当前运算符，运算符入栈 
						ind.push(4);
						break;	
					}else{//栈顶运算符大于等于当前运算符，栈顶运算符出栈，算术运算 
						double x,y;
						y=num.top();//第二个数
						num.pop(); 
						x=num.top();//第一个数 
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
