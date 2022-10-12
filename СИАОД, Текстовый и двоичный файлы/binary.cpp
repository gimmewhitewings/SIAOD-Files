#include <iostream>
#include <locale.h>
#include <fstream>
#include "binWork.h"
#include "filework.h"


using namespace std;


int main() {
	setlocale(LC_ALL, "ru");

	int task = -1;
	string binFileName = "test.dat";
	string currentDate = "2022.10.03";
	string targetTextFile;
	string targetBinFile;
	int cardNumber;
	int keyNumber, keyInvenotoryNumber;
	libraryCard* demoCardPtr;
	libraryCard demoCard;
	cout << "������� �������� ��������� ����� (name.dat): ";
	cin >> binFileName;
	cout << "������� ����������� ���� � ������� ����.��.�� : ";
	cin >> currentDate;

	while (task != 0)
	{
		system("cls");
		cout << "������������ ������ �2. ��������� �.�. ����-06-21. ������� 18\n"
			"1 - �������������� �������� ������ �� ���������� ����� � �������� ����\n"
			"2 - �������������� ������ �� ��������� ����� � ���������\n"
			"3 - ����� ���� ������� ��������� �����\n"
			"4 - ������ � ������ �� �� ����������� ������ � �����\n"
			"5 - �������� ������ � �������� ��������� �����\n"
			"6 - ������������ ������ ���������, ������� �� ������� ����� � ���� (���� �������� < �������)\n"
			"7 - ����� ������ �� �������� ���������: �����, ����������� �����\n"
			"8 - ������� ������ � ������, ������� �������� ������� � ����������\n"
			"0 - ����������� ��������\n"
			"������� ����� �������: ";
		cin >> task;
		switch (task)
		{
		case 1:
			cout << "������, ���������� � ��������� ����:\n";
			printFile("start.txt");
			txtToBin("start.txt", binFileName);
			cout << "������ � �������� ���� ������� ���������.\n";
			system("pause");
			break;
		case 2:
			cout << "������� �������� ���������� �����, � ������� ����� �������������� ������: ";
			cin >> targetTextFile;
			binToTxt(targetTextFile, binFileName);
			cout << "������ � ��������� ���� ������� ���������.\n\n";
			cout << "�� ������ ������ � ��������� ����� �������� ��������� ������:\n";
			printFile(targetTextFile);
			system("pause");
			break;
		case 3:
			cout << "�� ������ ������ � �������� ����� �������� ��������� ������:\n";
			printBinFile(binFileName);
			system("pause");
			break;
		case 4:
			cout << "������� ����� ������, ������� ������ �������: ";
			cin >> cardNumber;
			cout << getCardByNumber(binFileName, cardNumber) << '\n';
			system("pause");
			break;
		case 5:	
			cout << "�� ������ ������ � �������� ����� �������� ��������� ������:\n";
			printBinFile(binFileName);
			cout << "\n������� ���� ������, ������� ������ ������� (������ �� ��������� ������ � �����): ";
			cin >> keyNumber;
			if (deleteCardByKey(binFileName, keyNumber))
			{
				cout << "\n������ �������� ���� ����� ��������� ���:\n";
				printBinFile(binFileName);
			}
			else
			{
				cout << "\n�� ������� ����� ������ � �������� ��������� �����.\n";
			}
			system("pause");
			break;
		case 6:
			cout << "������� ��� ��������� �����, � ������� ����� �������������� ������: ";
			cin >> targetBinFile;
			expiredBooks(binFileName, targetBinFile, currentDate);
			cout << "� ����� " << targetBinFile << " �������� ��������� ������:\n";
			printBinFile(targetBinFile);
			system("pause");
			break;
		case 7:
			cout << "������� ����� ������������� ������: ";
			cin >> keyNumber;
			cout << "������� ����������� ����� �����: ";
			cin >> keyInvenotoryNumber;
			demoCardPtr = getCardByKeys(binFileName, keyNumber, keyInvenotoryNumber);
			if (demoCardPtr != nullptr)
			{
				demoCard = *demoCardPtr;
				cout << "��� ������ ������ � ���� ��������� ������:\n";
				cout << demoCard.number << '\n'
					<< demoCard.inventoryNumber << '\n'
					<< demoCard.issueDate << '\n'
					<< demoCard.returnDate << '\n';
			}
			else
			{
				cout << "������ � ������ ������� �� ���������� � �����.\n";
			}
			system("pause");
			break;
		case 8:
			deleteReturnedBooks(binFileName, currentDate);
			cout << "����� �������� ������� � ������, ������� �������� ������� � ���������� ���� �������� ��� ���:\n";
			printBinFile(binFileName);
			system("pause");
			break;
		case 0:
			cout << "�������, �� ��������!\n";
			break;
		default:
			break;
		}
	}

	return 0;
}