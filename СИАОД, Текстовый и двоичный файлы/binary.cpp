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
	cout << "Введите название бинарного файла (name.dat): ";
	cin >> binFileName;
	cout << "Введите сегодняшнюю дату в формате ГГГГ.ММ.ДД : ";
	cin >> currentDate;

	while (task != 0)
	{
		system("cls");
		cout << "Практическая работа №2. Поведенок С.С. ИКБО-06-21. Вариант 18\n"
			"1 - Преобразование тестовых данных из текстового файла в двоичный файл\n"
			"2 - Преобразование данных из двоичного файла в текстовый\n"
			"3 - Вывод всех записей двоичного файла\n"
			"4 - Доступ к записи по ее порядковому номеру в файле\n"
			"5 - Удаление записи с заданным значением ключа\n"
			"6 - Сформировать список читателей, которые не вернули книги в срок (дата возврата < текущей)\n"
			"7 - Найти запись по заданным критериям: номер, инвентарный номер\n"
			"8 - Удалить записи о книгах, которые читатели вернули в библиотеку\n"
			"0 - Заверешение проверки\n"
			"Введите номер задания: ";
		cin >> task;
		switch (task)
		{
		case 1:
			cout << "Записи, хранящиеся в текстовом фале:\n";
			printFile("start.txt");
			txtToBin("start.txt", binFileName);
			cout << "Запись в двоичный файл успешно выполнена.\n";
			system("pause");
			break;
		case 2:
			cout << "Введите название текстового файла, в который будет осуществляться запись: ";
			cin >> targetTextFile;
			binToTxt(targetTextFile, binFileName);
			cout << "Запись в текстовый файл успешно выполнена.\n\n";
			cout << "На даныый момент в текстовом файле хранятся следующие записи:\n";
			printFile(targetTextFile);
			system("pause");
			break;
		case 3:
			cout << "На даныый момент в двоичном файле хранятся следующие записи:\n";
			printBinFile(binFileName);
			system("pause");
			break;
		case 4:
			cout << "Введите номер записи, которую хотите вывести: ";
			cin >> cardNumber;
			cout << getCardByNumber(binFileName, cardNumber) << '\n';
			system("pause");
			break;
		case 5:	
			cout << "На даныый момент в двоичном файле хранятся следующие записи:\n";
			printBinFile(binFileName);
			cout << "\nВведите ключ записи, которую хотите удалить (замена на последнюю запись в файле): ";
			cin >> keyNumber;
			if (deleteCardByKey(binFileName, keyNumber))
			{
				cout << "\nТеперь двоичный файл имеет следующий вид:\n";
				printBinFile(binFileName);
			}
			else
			{
				cout << "\nНе удалось найти запись с заданным значением ключа.\n";
			}
			system("pause");
			break;
		case 6:
			cout << "Введите имя двоичного файла, в который будет осуществляться запись: ";
			cin >> targetBinFile;
			expiredBooks(binFileName, targetBinFile, currentDate);
			cout << "В файле " << targetBinFile << " хранятся следующие данные:\n";
			printBinFile(targetBinFile);
			system("pause");
			break;
		case 7:
			cout << "Введите номер читательского билета: ";
			cin >> keyNumber;
			cout << "Введите инвентарный номер книги: ";
			cin >> keyInvenotoryNumber;
			demoCardPtr = getCardByKeys(binFileName, keyNumber, keyInvenotoryNumber);
			if (demoCardPtr != nullptr)
			{
				demoCard = *demoCardPtr;
				cout << "Эта запись хранит в себе следующие данные:\n";
				cout << demoCard.number << '\n'
					<< demoCard.inventoryNumber << '\n'
					<< demoCard.issueDate << '\n'
					<< demoCard.returnDate << '\n';
			}
			else
			{
				cout << "Записи с такими данными не существует в файле.\n";
			}
			system("pause");
			break;
		case 8:
			deleteReturnedBooks(binFileName, currentDate);
			cout << "После удаления записей о книгах, которые читатели вернули в библиотеку файл выглядит вот так:\n";
			printBinFile(binFileName);
			system("pause");
			break;
		case 0:
			cout << "Спасибо, до свидания!\n";
			break;
		default:
			break;
		}
	}

	return 0;
}