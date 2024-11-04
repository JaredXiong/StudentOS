#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "StudentStruct.h"
#include "menu.h"

void MainMenu(student* stu, int length) {

    printf("-----------------------------------------\n");
    printf("|        欢迎使用学生信息管理系统       |\n");
    printf("-----------------------------------------\n");
    int fnum;
    while (1) {
        printf("*****************************************\n");
        printf("*            1、录入学生信息            *\n");
        printf("*            2、查找学生信息            *\n");
        printf("*            3、删除学生信息            *\n");
        printf("*            4、修改学生信息            *\n");
        printf("*            5、插入学生信息            *\n");
        printf("*            6、按总成绩排序            *\n");
        printf("*            7、统计学生总数            *\n");
        printf("*            8、显示所有学生信息        *\n");
        printf("*            0、退出系统                *\n");
        printf("*****************************************\n");
        printf("请输入功能编号(0-8)：");
        fnum = getch();
        switch (fnum) {
        case 49:
            system("cls");
            length = in(stu, length); //录入信息
            break;
        case 50:
            system("cls");
            search(stu, length); //查找信息
            break;
        case 51:
            system("cls");
            length = del(stu, length); //删除信息
            break;
        case 52:
            system("cls");
            modify(stu, length); //修改信息
            break;
        case 53:
            system("cls");
            length = insert(stu, length); //插入信息
            break;
        case 54:
            system("cls");
            order(stu, length); //按总分排序
            break;
        case 55:
            system("cls");
            total(stu, length); //统计总人数
            break;
        case 56:
            system("cls");
            show(stu, length); //显示信息
            break;
        case 48:
            return;
        default:
            system("cls");
            printf("请输入正确的指令编号！\n");
            break;
        }
    }
}

int main(){
    student stu[50];
    int length = 0;
    MainMenu(stu, length);
    printf("\nGood bye!\n");
    Sleep(1000);
    return 0;
}
