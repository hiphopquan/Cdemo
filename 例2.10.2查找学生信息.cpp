#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Student{ //���ڱ�ʾѧ������Ľṹ��
char no[100]; //ѧ��
char name[100]; //����
int age; //����
char sex[5]; //�Ա�
bool operator < (const Student & A) const { //����С�������ʹ����ʹ��sort��������
return strcmp(no,A.no) < 0;
}
}buf[1000];
int main () {
int n;
while (scanf ("%d",&n) != EOF) {
for (int i = 0;i < n;i ++) {
scanf ("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
} //����
sort(buf,buf + n); //����������ʹ�䰴��ѧ����������
int t;
scanf ("%d",&t); //��t��ѯ��
while (t -- != 0) { //whileѭ����֤��ѯ����Ϊt
int ans = -1; //Ŀ��Ԫ���±�,��ʼ��Ϊ-1
char x[30];
scanf ("%s",x); //������ѧ��
int top = n - 1,base = 0; //����ʱ����ʼ�±�0,�����±�n-1,�����Ӽ�Ϊ��������
while(top >= base) { //�������Ӽ���Ϊ�ռ�ʱ�ظ����ֲ���
int mid = (top + base) / 2; //�����м���±�
int tmp = strcmp(buf[mid].no,x); //�Ƚ��м��ѧ����Ŀ��ѧ��
if (tmp == 0) {
ans = mid;
break; //�����,���������������ֲ���
}
else if (tmp > 0) top = mid - 1; // ������,������±��Ϊ�м��ǰһ�����±�
else base = mid + 1; //��С��,��ʼ���±��Ϊ�м���һ��������
}
if (ans == -1) { //������ʧ��
printf("No Answer!\n");
}
else printf("%s %s %s %d\n",
buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age); //�����ҳɹ�
}
}
return 0;
}
