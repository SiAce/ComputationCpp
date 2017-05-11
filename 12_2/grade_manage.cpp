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
		cout << "��ӭʹ�óɼ�����ϵͳ��\n"
			<< "1--���ѧ����Ϣ\n"
			<< "2--�޸�ѧ����Ϣ\n"
			<< "3--��ʾȫ��ѧ����Ϣ\n"
			<< "4--��ѧ�Ų�ѯѧ����Ϣ\n"
			<< "5--��������ѯѧ����Ϣ\n"
			<< "6--��ѧ����������\n"
			<< "7--���ֽܷ�������\n"
			<< "0--�˳�" << endl;
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
	cout << "��������ѧ����ѧ�š���������ѧ�ɼ���Ӣ��ɼ�������ɼ�" << endl;
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

	cout << "1--��ѧ���޸�ѧ����Ϣ\n" << "2--�������޸�ѧ����Ϣ" << endl;
	cin >> opt;

	switch (opt)
	{
	case 1:
		opt = -1;
		cout << "������Ҫ�޸ĵ�ѧ����ѧ��" << endl;
		cin >> number;
		for (i = 0; i < num; i++) {
			if (strcmp(number, students[i].num) == 0)  {
				index = i;
			}
		}

		while (opt != 0) {
			cout << "Ҫ�޸���Щ���ݣ�\n"
				<< "1--ѧ��\n"
				<< "2--����\n"
				<< "3--��ѧ�ɼ�\n"
				<< "4--Ӣ��ɼ�\n"
				<< "5--����ɼ�\n"
				<< "0--�˳�" << endl;
			cin >> opt;

			switch (opt)
			{
			case 1:
				cout << "������ѧ��" << endl;
				cin >> students[index].num;
				break;
			case 2:
				cout << "����������" << endl;
				cin >> students[index].name;
				break;
			case 3:
				cout << "�����µ���ѧ�ɼ�" << endl;
				cin >> students[index].math;
				break;
			case 4:
				cout << "�����µ�Ӣ��ɼ�" << endl;
				cin >> students[index].english;
				break;
			case 5:
				cout << "�����µ�����ɼ�" << endl;
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
		cout << "������Ҫ�޸ĵ�ѧ��������" << endl;
		cin >> name;
		for (i = 0; i < num; i++) {
			if (strcmp(name, students[i].name) == 0) {
				index = i;
			}
		}

		while (opt != 0) {
			cout << "Ҫ�޸���Щ���ݣ�\n"
				<< "1--ѧ��\n"
				<< "2--����\n"
				<< "3--��ѧ�ɼ�\n"
				<< "4--Ӣ��ɼ�\n"
				<< "5--����ɼ�\n"
				<< "0--�˳�" << endl;
			cin >> opt;

			switch (opt)
			{
			case 1:
				cout << "������ѧ��" << endl;
				cin >> students[index].num;
				break;
			case 2:
				cout << "����������" << endl;
				cin >> students[index].name;
				break;
			case 3:
				cout << "�����µ���ѧ�ɼ�" << endl;
				cin >> students[index].math;
				break;
			case 4:
				cout << "�����µ�Ӣ��ɼ�" << endl;
				cin >> students[index].english;
				break;
			case 5:
				cout << "�����µ�����ɼ�" << endl;
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
	cout << "������Ҫ��ѯ��ѧ��" << endl;
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
	cout << "������Ҫ��ѯ������" << endl;
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