#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "StudentStruct.h"

void MainMenu(student* stu, int length);//主菜单
int in(student* stu, int length);//录入信息
void search(student* stu, int length);//查找信息
int del(student* stu, int length);//删除信息
void modify(student* stu, int length);//修改信息
int insert(student* stu, int length);//插入信息
void order(student* stu, int length);//按总分排序
void total(student* stu, int length);//统计总人数
void show(student* stu, int length);//显示信息

#endif
