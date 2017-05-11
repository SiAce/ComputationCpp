#include<iostream>

using namespace std;

int i;
int num = 0;

struct studentT {
	char num[15];
	char name[10];
	int math;
	int english;
	int physics;
	int total;
};

studentT students[100];

void Add();
void Modify();
void ShowAll();
void NumQuery();
void NameQuery();
void NumSort();
void GradeSort();

int main() 
{
	int opt = -1;

	while (opt != 0) 
	{
		cout << "欢迎使用成绩管理系统！\n"
			<< "1--添加学生信息\n"
			<< "2--修改学生信息\n"
			<< "3--显示全部学生信息\n"
			<< "4--按学号查询学生信息\n"
			<< "5--按姓名查询学生信息\n"
			<< "6--按学号升序排序\n"
			<< "7--按总分降序排序\n"
			<< "0--退出" << endl;
		cin >> opt;

		switch (opt) 
		{
		case 1:
			Add();
			break;
		case 2:
			Modify();
			break;
		case 3:
			ShowAll();
			break;
		case 4:
			NumQuery();
			break;
		case 5:
			NameQuery();
			break;
		case 6:
			NumSort();
			break;
		case 7:
			GradeSort();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	return 0;
}

void Add() {
	cout << "依次输入学生的学号、姓名、数学成绩、英语成绩、物理成绩" << endl;
	cin >> students[num].num >> students[num].name
		>> students[num].math >> students[num].english >> students[num].physics;
	students[num].total = students[num].math 
		+ students[num].english + students[num].physics;
	++num;
}

void Modify() {
	int opt, index;
	char number[15];
	char name[10];

	cout << "1--按学号修改学生信息\n" << "2--按姓名修改学生信息" << endl;
	cin >> opt;

	switch (opt)
	{
	case 1:
		opt = -1;
		cout << "请输入要修改的学生的学号" << endl;
		cin >> number;
		for (i = 0; i < num; i++) {
			if (strcmp(number, students[i].num) == 0)  {
				index = i;
			}
		}

		while (opt != 0) {
			cout << "要修改哪些内容？\n"
				<< "1--学号\n"
				<< "2--姓名\n"
				<< "3--数学成绩\n"
				<< "4--英语成绩\n"
				<< "5--物理成绩\n"
				<< "0--退出" << endl;
			cin >> opt;

			switch (opt)
			{
			case 1:
				cout << "输入新学号" << endl;
				cin >> students[index].num;
				break;
			case 2:
				cout << "输入新姓名" << endl;
				cin >> students[index].name;
				break;
			case 3:
				cout << "输入新的数学成绩" << endl;
				cin >> students[index].math;
				break;
			case 4:
				cout << "输入新的英语成绩" << endl;
				cin >> students[index].english;
				break;
			case 5:
				cout << "输入新的物理成绩" << endl;
				cin >> students[index].physics;
				break;
			case 0:
				break;
			default:
				break;
			}
		}

		students[index].total = students[index].math
			+ students[index].english + students[index].physics;
		break;
	case 2:
		opt = -1;
		cout << "请输入要修改的学生的姓名" << endl;
		cin >> name;
		for (i = 0; i < num; i++) {
			if (strcmp(name, students[i].name) == 0) {
				index = i;
			}
		}

		while (opt != 0) {
			cout << "要修改哪些内容？\n"
				<< "1--学号\n"
				<< "2--姓名\n"
				<< "3--数学成绩\n"
				<< "4--英语成绩\n"
				<< "5--物理成绩\n"
				<< "0--退出" << endl;
			cin >> opt;

			switch (opt)
			{
			case 1:
				cout << "输入新学号" << endl;
				cin >> students[index].num;
				break;
			case 2:
				cout << "输入新姓名" << endl;
				cin >> students[index].name;
				break;
			case 3:
				cout << "输入新的数学成绩" << endl;
				cin >> students[index].math;
				break;
			case 4:
				cout << "输入新的英语成绩" << endl;
				cin >> students[index].english;
				break;
			case 5:
				cout << "输入新的物理成绩" << endl;
				cin >> students[index].physics;
				break;
			case 0:
				break;
			default:
				break;
			}
		}

		students[index].total = students[index].math
			+ students[index].english + students[index].physics;
		break;
	default:
		break;
	}
}

void ShowAll() {
	for (i = 0; i < num; i++) {
		cout << students[i].num << " " << students[i].name << " "
			<< students[i].math << " " << students[i].english << " "
			<< students[i].physics << endl;
	}
}

void NumQuery() {
	i = 0;
	char number[15];
	cout << "请输入要查询的学号" << endl;
	cin >> number;
	for (i = 0; i < num; i++) {
		if (strcmp(students[i].num, number) == 0) {
			cout << students[i].num << " " << students[i].name << " "
				<< students[i].math << " " << students[i].english << " "
				<< students[i].physics << endl;
		}
		++i;
	}
}

void NameQuery() {
	i = 0;
	char name[10];
	cout << "请输入要查询的姓名" << endl;
	cin >> name;
	for (i = 0; i < num; i++) {
		if (strcmp(students[i].name, name) == 0) {
			cout << students[i].num << " " << students[i].name << " "
				<< students[i].math << " " << students[i].english << " "
				<< students[i].physics << endl;
		}
		++i;
	}
}

void NumSort() {
	studentT tmp;
	int j;
	bool flag;

	for (i = 1; i <= num ; i++) {
		flag = false;

		for (j = 0; j < num - i; j++) {
			if (strcmp(students[j].num, students[j + 1].num) > 0) {
				tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
				flag = true;
			}
		}

		if (!flag) {
			break;
		}
	}
}

void GradeSort() {
	studentT tmp;
	int j;
	bool flag;

	for (i = 1; i <= num; i++) {
		flag = false;

		for (j = 0; j < num - i; j++) {
			if (students[j].total < students[j + 1].total) {
				tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
				flag = true;
			}
		}

		if (!flag) {
			break;
		}
	}
}