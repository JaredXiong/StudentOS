#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "StudentStruct.h"
#include "menu.h"

void MainMenu(student* stu, int length) {

    printf("-----------------------------------------\n");
    printf("|        ��ӭʹ��ѧ����Ϣ����ϵͳ       |\n");
    printf("-----------------------------------------\n");
    int fnum;
    while (1) {
        printf("*****************************************\n");
        printf("*            1��¼��ѧ����Ϣ            *\n");
        printf("*            2������ѧ����Ϣ            *\n");
        printf("*            3��ɾ��ѧ����Ϣ            *\n");
        printf("*            4���޸�ѧ����Ϣ            *\n");
        printf("*            5������ѧ����Ϣ            *\n");
        printf("*            6�����ܳɼ�����            *\n");
        printf("*            7��ͳ��ѧ������            *\n");
        printf("*            8����ʾ����ѧ����Ϣ        *\n");
        printf("*            0���˳�ϵͳ                *\n");
        printf("*****************************************\n");
        printf("�����빦�ܱ��(0-8)��");
        fnum = getch();
        switch (fnum) {
        case 49:
            system("cls");
            length = in(stu, length); //¼����Ϣ
            break;
        case 50:
            system("cls");
            search(stu, length); //������Ϣ
            break;
        case 51:
            system("cls");
            length = del(stu, length); //ɾ����Ϣ
            break;
        case 52:
            system("cls");
            modify(stu, length); //�޸���Ϣ
            break;
        case 53:
            system("cls");
            length = insert(stu, length); //������Ϣ
            break;
        case 54:
            system("cls");
            order(stu, length); //���ܷ�����
            break;
        case 55:
            system("cls");
            total(stu, length); //ͳ��������
            break;
        case 56:
            system("cls");
            show(stu, length); //��ʾ��Ϣ
            break;
        case 48:
            return;
        default:
            system("cls");
            printf("��������ȷ��ָ���ţ�\n");
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
