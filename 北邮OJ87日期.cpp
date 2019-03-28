#include<stdio.h>

int dayOfMonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};

int isYear(int y){
	if(y%100!=0&&y%4==0||y%400==0){
		return 1;
	}else{
		return 0;
	}
}
int days[2100][13][32];
int Year=0;
int Month=1;
int Day=1;
void nextDay(){
	Day++;
	if(Day>dayOfMonth[Month][isYear(Year)]){
		Day=1;
		Month++;
		if(Month>12){
			Month=1;
			Year++;
		}
	}
}

void init(){
	int d=1;
	while(Year!=2100){
		days[Year][Month][Day]=d++;
//		printf("%d\n",days[Year][Month][Day]);
		nextDay();
	}
}

int main(){
	int t;
	int y,m,d;
	init();
//	return 0;
	while(scanf("%d",&t)!=EOF){
		for(int i=0;i<t;i++){
			scanf("%d:%d:%d",&y,&m,&d);
			int ans=days[y][m][d]-days[y][1][1]+1;
			printf("%d\n",ans);
		}
	}
}
