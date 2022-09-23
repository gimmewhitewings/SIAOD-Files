#pragma once
#include <fstream>
#include <string>

using namespace std;

void createFile(string fileName)
{
	ofstream fout(fileName);
	string str;
	int lines;
	cin >> lines;
	cin.ignore();
	for (size_t i = 0; i < lines; i++)
	{
		getline(cin, str);
		fout << str << '\n';
	}
	fout.close();
}


void printFile(string fileName) {
	ifstream fin(fileName);
	string line;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			cout << line << endl;
		}
	}
	fin.close();
}

string readFile(string fileName) {
	ifstream fin(fileName);
	string line;
	string result;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			result += line + '\n';
		}
	}
	fin.close();
	return result;
}

void addString(string fileName, string newString) {
	ofstream fout(fileName, ios::app);
	if (fout.is_open())
	{
		fout << newString;
	}
	fout.close();
}

void writeString(string fileName, string newString) {
	ofstream fout(fileName);
	if (fout.is_open())
	{
		fout << newString;
	}
	fout.close();
}

int readNumber(string fileName, int number) {
	ifstream fin(fileName);
	string token;
	size_t i = 0;
	bool isFound = false;
	int value = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> token;
			try // �������� �� ��, ��� ������� "�����" �������� ������
			{
				stoi(token);
				i++; // ���������� ���������� ����� �����
				if (i == number) // ���������� � ������� ���������� �������
				{
					// ���� ���������� ������ ��������� - ����������� ��������� ����� 
					value = stoi(token);
					isFound = true;
					fin.close();
					return value; // ���������� ��������� �����
				}
			}
			catch (const std::exception&)
			{
				continue;
			}
		}
	}

	if (!isFound)
	{
		throw std::invalid_argument("Index is not found");
	}

	fin.close();
}

int countNumbers(string fileName) {
	ifstream fin(fileName);
	string line;
	size_t pos = 0;
	size_t count = 0;
	int value = 0;
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			size_t pos = 0;
			string token;
			// ���� ������ �������� �����������
			while (pos = line.find(" ") != string::npos)
			{
				token = line.substr(0, pos); // ��������� ������ �� ������� ����������� = ��������� "�����"
				try // �������� �� ��, ��� ������� "�����" �������� ������
				{
					stoi(token);
					count++; // ���������� ���������� �����
				}
				catch (const std::exception&)
				{
					continue;
				}

				line.erase(0, pos + 1); // ������� �� ������ ������� "�����"
			}

			// ���� ������ �� �������� ������������ (���� �����)
			// ��������� ��� ������ �� ���� �����
			try // �������� �� ��, ��� ������� "�����" �������� ������
			{
				stoi(line);
				count++;
			}
			catch (const std::exception&)
			{
				continue;
			}
		}
	}
	fin.close();
	return count;
}
