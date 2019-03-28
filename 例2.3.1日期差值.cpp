#include<stdio.h>
#define ISYEAR(x) x%100!=0&&x%4==0|x%400==0 ? 1 : 0
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
struct Date{
	int Year;
	int Month;
	int Day;
	
	void nextDay(){
		Day++;
		if(Day>dayOfMonth[Month][ISYEAR(Year)]){
			Day=1;
			Month++;
		}
		if(Month>12){
			Month=1;
			Year++;
		}
		
	}
	
};

int buf[5001][13][32];
int Abs(int x){
	return x>0 ? x : -x;
}
int main(){
	Date tmp;
	int cnt=0;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	while(tmp.Year!=5001){
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
		cnt++;
		tmp.nextDay();
	}
	int y1,m1,d1;
	int y2,m2,d2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d",Abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
	}
	return 0;
}
