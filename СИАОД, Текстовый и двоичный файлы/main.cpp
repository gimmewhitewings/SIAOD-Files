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
		cout << "Практическая работа №2. Работа с текстовым файлом. Поведенок С.С. Вариант 18\n"
			"1 - Создать текстовый файл\n"
			"2 - Вывести содержимое текстового файла\n"
			"3 - Добавление новой строки в конец файла\n"
			"4 - Прочитать значение числа\n"
			"5 - Определить количество чисел в файле\n"
			"6 - Создать новый файл из значений исходного, размещая на строке по три числа из исходного файла.\n"
			"0 - Завершить проверку\n"
			"Введите номер задания: ";
		cin >> task;
		switch (task)
		{
		case 1:
			cout << "Введите имя текстового файла: ";
			cin >> fileName;
			cout << "Введите количество строк в файле: ";
			cin >> lines;
			cout << "Введите содержимое файла:\n";
			createFile(fileName, lines);
			system("pause");
			break;
		case 2:
			cout << "Введите имя текстового файла: ";
			cin >> fileName;
			cout << "Содержимое файла " << fileName << ": \n";
			printFile(fileName);
			system("pause");
			break;
		case 3:
			cout << "Введите имя текстового файла: ";
			cin >> fileName;
			cout << "Введите строку, которую необходимо добавить: ";
			cin.ignore();
			getline(cin, newString);
			addString(fileName, newString);
			cout << "Теперь содержимое файла выглядит вот так:\n";
			printFile(fileName);
			system("pause");
			break;
		case 4:
			cout << "Введите имя текстового файла: ";
			cin >> fileName;
			cout << "Введите номер числа, которое вы хотите прочитать: ";
			cin >> number;
			try
			{
				cout << "Число под номером " << number << ": " << readNumber(fileName, number) << endl;
			}
			catch (const std::exception&)
			{
				cout << "Не удалось найти в файле число с таким номером\n";
			}
			system("pause");
			break;
		case 5:
			cout << "Введите имя текстового файла: ";
			cin >> fileName;
			cout << "В данном файле содержится " << countNumbers(fileName) << " чисел\n";
			system("pause");
			break;
		case 6:
			cout << "Введите имя изначального текстового файла: ";
			cin >> fileName;
			cout << "Введите имя файла, создаваемого в результате выполнения программы: ";
			cin >> newFile;
			threeInRow(fileName, newFile);
			cout << "Теперь в файле " << newFile << " хранятся следующие данные:";
			printFile(newFile);
			system("pause");
			break;
		case 0:
			cout << "Спасибо, до свидания.\n";
			system("pause");
			break;
		default:
			cout << "Извините, не удалось распознать команду. Попробуйте ещё раз\n";
			system("pause");
			break;
		}
	}
	return 0;
}