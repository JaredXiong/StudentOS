#ifndef STUDENTSTRUCT_H_INCLUDED
#define STUDENTSTRUCT_H_INCLUDED

typedef struct student {
	int num;//学号
	char name[15];//姓名
	char telnum[12];//手机号码
	double expe;//平时成绩
	double requ;//期末成绩
	double sum;//总成绩
}student;

#endif
