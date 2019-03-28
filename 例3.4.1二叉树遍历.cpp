#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct tree{
	tree *lchild;
	tree *rchild;
	char c;
}Tree; 
char prior[27];
char mid[27];
Tree *build(int s1,int e1,int s2,int e2){
	int ind;
	Tree * s;
	for(int j=s2;j<=e2;j++){
		if(mid[j]==prior[s1]){
			s=(Tree *)malloc(sizeof(Tree));
			s->c=mid[j];
			s->lchild=NULL;
			s->rchild=NULL;
			ind=j;		
			break;
		}	
	}	
	if(ind!=s2){//有左子树 
		s->lchild=build(s1+1,s1+(ind-s2),s2,ind-1);
	}
	if(ind!=e2){//有右子树 
		s->rchild=build(s1+(ind-s2)+1,e1,ind+1,e2);
	}
	return s;
}
void post(Tree *p){

	if(p->lchild!=NULL){
		post(p->lchild);
	}
	if(p->rchild!=NULL){
		post(p->rchild);
	}
	printf("%c",p->c);
}
void front(Tree *p){
	printf("%c",p->c);
	if(p->lchild!=NULL){
		front(p->lchild);
	}
	if(p->rchild!=NULL){
		front(p->rchild);
	}
}
void middle(Tree *p){
	
	if(p->lchild!=NULL){
		middle(p->lchild);
	}
	printf("%c",p->c);
	if(p->rchild!=NULL){
		middle(p->rchild);
	}
}
int main(){
	while(scanf("%s",prior)!=EOF){
		scanf("%s",mid);
		int L1=strlen(prior);
		int L2=strlen(mid);
		Tree * p=build(0,L1-1,0,L2-1);
		post(p);		
	}
	return 0;
}
