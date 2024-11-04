#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable:6031)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "StudentStruct.h"
#include "menu.h"

//��ѧ����Ϣ��������ʹ�õ���ð������
static void Bubble_sort(student* stu, int length) {
	for (int i = 0; i < length; i++) {
		int flag = 0;
		for (int j = 0; j < length - 1; j++) {
			if (stu[j].num > stu[j + 1].num) {
				student temp;//���������ṹ��
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
//��ӡѧ����Ϣ
static void Print(student* stu, int length) {
	printf("---------------------------------------------------------------------------------\n");
	printf("|ѧ��\t\t����\t�绰����\tƽʱ�ɼ�\t��ĩ�ɼ�\t�ܳɼ�\t|\n");
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

//¼����Ϣ
int in(student* stu, int length) {
	if (length < 50) {
		int i;
		printf("Ŀǰ���ܴ洢%dλͬѧ����Ϣ����������Ҫ�������λͬѧ����Ϣ��", 50 - length);
		scanf("%d", &i);
		if (i <= 50 - length) {
			for (int j = 1; j <= i; j++) {
				printf("�������%dλͬѧ��ѧ�š��������ֻ����롢ƽʱ�ɼ�����ĩ�ɼ����ܳɼ�,�ÿո�ָ���\n", j);
				scanf("%d %s %s %lf %lf %lf", &stu[length].num, stu[length].name, stu[length].telnum,
					&stu[length].expe, &stu[length].requ, &stu[length].sum);
				length++;
			}
			Bubble_sort(stu, length);
		}
		else
			printf("����ռ䲻�㣡");
	}
	else {
		printf("����ռ䲻�㣡");
	}
	printf("�������������\n");
	getch();
	system("cls");
	return length;
}

//������Ϣ
void search(student* stu, int length) {
	int sear,no;
	char nam[15];
	char tele[12];
	printf("�������ѯ������ţ�\n  1����ѧ�Ų�ѯ\n  2����������ѯ\n  3�����ֻ������ѯ\n  0������\n");
	scanf("%d", &sear);
	switch (sear) {
	case(1):
		printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
		scanf("%d", &no);
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (no == stu[i].num) {
				printf("ѧ��ѧ�ţ�%d\t������%s\t�ֻ����룺%s\tƽʱ�ɼ���%.2f\t��ĩ�ɼ���%.2f\t�ܳɼ���%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("��ѧ�������ڣ�");
		}
		break;
	case(2):
		printf("��������Ҫ��ѯ��ѧ��������");
		scanf("%s", nam);
		nam[strlen(nam)] = '\0';
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (strcmp(nam, stu[i].name) == 0) {
				printf("ѧ��ѧ�ţ�%d\t������%s\t�ֻ����룺%s\tƽʱ�ɼ���%.2f\t��ĩ�ɼ���%.2f\t�ܳɼ���%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("��ѧ�������ڣ�");
		}
		break;
	case(3):
		printf("��������Ҫ��ѯ��ѧ���ֻ����룺");
		scanf("%s", tele);
		tele[strlen(tele)] = '\0';
		for (int i = 0; i < length; i++) {
			int m = 0;
			if (strcmp(stu[i].telnum, tele) == 0) {
				printf("ѧ��ѧ�ţ�%d\t������%s\t�ֻ����룺%s\tƽʱ�ɼ���%.2f\t��ĩ�ɼ���%.2f\t�ܳɼ���%.2f\n",
					stu[i].num, stu[i].name, stu[i].telnum, stu[i].expe, stu[i].requ, stu[i].sum);
				m = 1;
			}
			if (m)
				break;
			else if (i == length - 1)
				printf("��ѧ�������ڣ�");
		}
		break;
	case(0):
		system("cls");
		return;
	default:
		printf("��������ȷ�������ţ�");
		break;
	}
	printf("�������������\n");
	getch();
	system("cls");
	return;
}
//ɾ����Ϣ
int del(student* stu, int length) {
	int n;
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            ��������Ҫɾ����ѧ��ѧ��                           |\n");
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
			printf("��ѧ�������ڣ�");
	}
	printf("ɾ���ɹ����������������\n");
	getch();
	system("cls");
	return length;
}
//�޸���Ϣ
void modify(student* stu, int length) {
	int n;
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            ��������Ҫ�޸ĵ�ѧ��ѧ��                           |\n");
	Print(stu, length);
	scanf("%d", &n);
	for (int i = 0; i < length; i++) {
		int m = 0;
		if (n == stu[i].num) {			
			char name[15], telnum[12];
			double expe, requ, sum;
			printf("�������µ��������ֻ����롢ƽʱ�ɼ�����ĩ�ɼ����ܳɼ�,�ÿո�ָ���\n");
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
			printf("��ѧ�������ڣ�");
	}
	printf("�޸ĳɹ����������������\n");
	getch();
	system("cls");
	return;

}
//������Ϣ
int insert(student* stu, int length) {
	if (length < 50) {
		printf("������ѧ�š��������ֻ����롢ƽʱ�ɼ�����ĩ�ɼ����ܳɼ�,�ÿո�ָ���\n");
		scanf("%d %s %s %lf %lf %lf", &stu[length].num, stu[length].name, stu[length].telnum,
			&stu[length].expe, &stu[length].requ, &stu[length].sum);
		length++;
		Bubble_sort(stu, length);
	}
	else {
		printf("����ռ䲻�㣡");
	}
	printf("�������������\n");
	getch();
	system("cls");
	return length;
	
}
//���ܷ�����
void order(student* stu, int length) {
	for (int i = 0; i < length; i++) {
		int flag = 0;
		for (int j = 0; j < length - 1; j++) {
			if (stu[j].sum < stu[j + 1].sum) {
				student temp;//���������ṹ��
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
	printf("�������������\n");
	getch();
	system("cls");
	return;
	
}
//ͳ��������
void total(student* stu, int length) {
	printf("��ǰϵͳ�й���%dλѧ����\n", length);
	printf("�������������\n");
	getch();
	system("cls");
	return;
	
}
//��ʾ��Ϣ
void show(student* stu, int length){
	printf("---------------------------------------------------------------------------------\n");
	printf("|                            ��ӭʹ��ѧ����Ϣ����ϵͳ                           |\n");
	Print(stu, length);
	printf("�������������\n");
	getch();
	system("cls");
	return;

}
