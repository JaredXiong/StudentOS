#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "StudentStruct.h"

void MainMenu(student* stu, int length);//���˵�
int in(student* stu, int length);//¼����Ϣ
void search(student* stu, int length);//������Ϣ
int del(student* stu, int length);//ɾ����Ϣ
void modify(student* stu, int length);//�޸���Ϣ
int insert(student* stu, int length);//������Ϣ
void order(student* stu, int length);//���ܷ�����
void total(student* stu, int length);//ͳ��������
void show(student* stu, int length);//��ʾ��Ϣ

#endif
