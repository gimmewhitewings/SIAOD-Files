#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "filework.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int task = -1;
	string fileName = "numbers.txt";
	string newFile = "formatedNumbers.txt";
	string newString;
	int lines;
	int number;
	while (task != 0)
	{
		system("cls");
		cout << "������������ ������ �2. ������ � ��������� ������. ��������� �.�. ������� 18\n"
			"1 - ������� ��������� ����\n"
			"2 - ������� ���������� ���������� �����\n"
			"3 - ���������� ����� ������ � ����� �����\n"
			"4 - ��������� �������� �����\n"
			"5 - ���������� ���������� ����� � �����\n"
			"6 - ������� ����� ���� �� �������� ���������, �������� �� ������ �� ��� ����� �� ��������� �����.\n"
			"0 - ��������� ��������\n"
			"������� ����� �������: ";
		cin >> task;
		switch (task)
		{
		case 1:
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "������� ���������� ����� � �����: ";
			cin >> lines;
			cout << "������� ���������� �����:\n";
			createFile(fileName, lines);
			system("pause");
			break;
		case 2:
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "���������� ����� " << fileName << ": \n";
			printFile(fileName);
			system("pause");
			break;
		case 3:
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "������� ������, ������� ���������� ��������: ";
			cin.ignore();
			getline(cin, newString);
			addString(fileName, newString);
			cout << "������ ���������� ����� �������� ��� ���:\n";
			printFile(fileName);
			system("pause");
			break;
		case 4:
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "������� ����� �����, ������� �� ������ ���������: ";
			cin >> number;
			try
			{
				cout << "����� ��� ������� " << number << ": " << readNumber(fileName, number) << endl;
			}
			catch (const std::exception&)
			{
				cout << "�� ������� ����� � ����� ����� � ����� �������\n";
			}
			system("pause");
			break;
		case 5:
			cout << "������� ��� ���������� �����: ";
			cin >> fileName;
			cout << "� ������ ����� ���������� " << countNumbers(fileName) << " �����\n";
			system("pause");
			break;
		case 6:
			cout << "������� ��� ������������ ���������� �����: ";
			cin >> fileName;
			cout << "������� ��� �����, ������������ � ���������� ���������� ���������: ";
			cin >> newFile;
			threeInRow(fileName, newFile);
			cout << "������ � ����� " << newFile << " �������� ��������� ������:";
			printFile(newFile);
			system("pause");
			break;
		case 0:
			cout << "�������, �� ��������.\n";
			system("pause");
			break;
		default:
			cout << "��������, �� ������� ���������� �������. ���������� ��� ���\n";
			system("pause");
			break;
		}
	}
	return 0;
}