#include<stdio.h>
#include<stdlib.h>
struct Node{
	Node *l;
	Node *r;
	int v;
};

Node *insert(Node *p,int tmp){
	if(p==NULL){
		p=(Node *)malloc(sizeof(Node));
		p->l=p->r=NULL;
		p->v=tmp;
		return p;
	}
	if(tmp>p->v){
		p->r=insert(p->r,tmp);
	}
	if(tmp<p->v){
		p->l=insert(p->l,tmp);
	}
	return p;
}
void preOrder(Node *p){
	printf("%d",p->v);
	if(p->l!=NULL){
		preOrder(p->l);
	}
	if(p->r!=NULL){
		preOrder(p->r);
	}
}
void inOrder(Node *p){
	
	if(p->l!=NULL){
		inOrder(p->l);
	}
	printf("%d",p->v);
	if(p->r!=NULL){
		inOrder(p->r);
	}
}
int flag=0;

void del(Node *&p,int x){
	Node *follow=p;
	Node *cur=p;
	while(cur->v!=x){
		if(x>cur->v){
			flag=1;
			follow=cur;
			cur=cur->r;
		}
		else if(cur->v!=x&&x<cur->v){
			flag=-1;
			follow=cur;
			cur=cur->l;
		}
	}
	if(x==cur->v){
		if(cur->l==NULL&&cur->r==NULL){//叶子结点 
			if(flag==1){
				follow->r=NULL;
				free(cur);
				
			}
			if(flag==-1){
				follow->l=NULL;
				free(cur);
			}
			flag=0;
		}else if(cur->l!=NULL&&cur->r==NULL){//仅有左子树 
			if(flag==1){
				follow->r=cur->l;
				free(cur);
				
			}
			if(flag==-1){
				follow->l=cur->l;
				free(cur);
			}
			flag=0;
		}else{//有右子树
			Node *tmp;
			tmp=follow;//保存最左下节点双亲 
			follow=cur->r; //查找右子树最左下 
			while(follow->l!=NULL){
				tmp=follow;
				follow=follow->l; 
			}
			cur->v=follow->v;
			tmp->l=follow->r;
		} 
	}
	
}
int main(){
	Node *p=NULL;
	int n,x;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			p=insert(p,tmp);
		}
		scanf("%d",&x);
		del(p,x);
		preOrder(p);
		printf("\n");
		inOrder(p);
	}
	return 0;
}
