#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable:6031)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "StudentStruct.h"
#include "menu.h"

//对学生信息进行排序，使用的是冒泡排序
static void Bubble_sort(student* stu, int length) {
	for (int i = 0; i < length; i++) {
		int flag = 0;
		for (int j = 0; j < length - 1; j++) {
			if (stu[j].num > stu[j + 1].num) {
				student temp;//交换两个结构体
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
	return;
}
//打印学生信息
static void Print(student* stu, int length) {
	printf("---------------------------------------------------------------------------------\n");
	printf("|学号\t\t姓名\t电话号码\t平时成绩\t期末成绩\t总成绩\t|\n");
	for (int i = 0; i < length; i++) {
		if (stu[i].num < 1000000)
			printf("|%d\t\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t|\n", stu[i].num, stu[i].name, stu[i].telnum,
				stu[i].expe, stu[i].requ, stu[i].sum);
		else
			printf("|%d\t%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t|\n", stu[i].num, stu[i].name, stu[i].telnum,
				stu[i].expe, stu[i].requ, stu[i].sum);
	}
	printf("---------------------------------------------------------------------------------\n");
}

//录入信息
int in(student* stu, int length) {
	if (length < 50) {
		int i;
		printf("目前还能存储%d位同学的信息，请问您需要输入多少位同学的信息？", 50 - length);
		scanf("%d", &i);
		if (i <= 50 - length) {
			for (int j = 1; j <= i; j++) {
				printf("请输入第%d位同学的学号、姓名、手机号码、平时成绩、期末成绩、总成绩,用空格分隔：\n", j);
				scanf("%d %s %s %lf %lf %lf", &stu[length].num, stu[length].name, stu[length].telnum,
					&stu[length].expe, &stu[length].requ, &stu[length].sum);
				length++;
			}
			Bubble_sort(stu, length);
		}
		else
			printf("数组空间不足！");
	}
	else {
		printf("数组空间不足！");
	}
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return length;
}

//查找信息
void search(student* stu, int length) {
	int sear,no;
	char nam[15];
	char tele[12];
	printf("请输入查询方法编号：\n  1、按学号查询\n  2、按姓名查询\n  3、按手机号码查询\n  0、返回\n");
	scanf("%d", &sear);
	switch (sear) {
	case(1):
		printf("请输入你要查询的学生学号：");
		scanf("%d", &no);
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (no == stu[i].num) {
				printf("学生学号：%d\t姓名：%s\t手机号码：%s\t平时成绩：%.2f\t期末成绩：%.2f\t总成绩：%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("该学生不存在！");
		}
		break;
	case(2):
		printf("请输入你要查询的学生姓名：");
		scanf("%s", nam);
		nam[strlen(nam)] = '\0';
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (strcmp(nam, stu[i].name) == 0) {
				printf("学生学号：%d\t姓名：%s\t手机号码：%s\t平时成绩：%.2f\t期末成绩：%.2f\t总成绩：%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("该学生不存在！");
		}
		break;
	case(3):
		printf("请输入你要查询的学生手机号码：");
		scanf("%s", tele);
		tele[strlen(tele)] = '\0';
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (strcmp(stu[i].telnum, tele) == 0) {
				printf("学生学号：%d\t姓名：%s\t手机号码：%s\t平时成绩：%.2f\t期末成绩：%.2f\t总成绩：%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("该学生不存在！");
		}
		break;
	case(0):
		system("cls");
		return;
	default:
		printf("请输入正确的命令编号！");
		break;
	}
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return;
}
//删除信息
int del(student* stu, int length) {
	int n;
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            请输入你要删除的学生学号                           |\n");
	Print(stu, length);
	scanf("%d", &n);
	for (int i = 0; i < length; i++) {
		int m = 0;
		if (n == stu[i].num) {
			for (int j = i; j < length; j++) {
				stu[j] = stu[j + 1];
			}
			m = 1;
			length--;
		}
		if (m)
			break;
		else if (i == length - 1)
			printf("该学生不存在！");
	}
	printf("删除成功，按任意键继续！\n");
	getch();
	system("cls");
	return length;
}
//修改信息
void modify(student* stu, int length) {
	int n;
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            请输入你要修改的学生学号                           |\n");
	Print(stu, length);
	scanf("%d", &n);
	for (int i = 0; i < length; i++) {
		int m = 0;
		if (n == stu[i].num) {			
			char name[15], telnum[12];
			double expe, requ, sum;
			printf("请输入新的姓名、手机号码、平时成绩、期末成绩、总成绩,用空格分隔：\n");
			scanf("%s %s %lf %lf %lf",name, telnum, &expe, &requ, &sum);
			name[strlen(name)] = '\0';
			telnum[strlen(telnum)] = '\0';
			strcpy(stu[i].name, name);
			strcpy(stu[i].telnum, telnum);
			stu[i].expe = expe;
			stu[i].requ = requ;
			stu[i].sum = sum;
			m = 1;
		}
		if (m)
			break;
		else if (i == length - 1)
			printf("该学生不存在！");
	}
	printf("修改成功，按任意键继续！\n");
	getch();
	system("cls");
	return;

}
//插入信息
int insert(student* stu, int length) {
	if (length < 50) {
		printf("请输入学号、姓名、手机号码、平时成绩、期末成绩、总成绩,用空格分隔：\n");
		scanf("%d %s %s %lf %lf %lf", &stu[length].num, stu[length].name, stu[length].telnum,
			&stu[length].expe, &stu[length].requ, &stu[length].sum);
		length++;
		Bubble_sort(stu, length);
	}
	else {
		printf("数组空间不足！");
	}
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return length;
	
}
//按总分排序
void order(student* stu, int length) {
	for (int i = 0; i < length; i++) {
		int flag = 0;
		for (int j = 0; j < length - 1; j++) {
			if (stu[j].sum < stu[j + 1].sum) {
				student temp;//交换两个结构体
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
	Print(stu, length);
	Bubble_sort(stu, length);
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return;
	
}
//统计总人数
void total(student* stu, int length) {
	printf("当前系统中共有%d位学生。\n", length);
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return;
	
}
//显示信息
void show(student* stu, int length){
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            欢迎使用学生信息管理系统                           |\n");
	Print(stu, length);
	printf("按任意键继续！\n");
	getch();
	system("cls");
	return;

}
