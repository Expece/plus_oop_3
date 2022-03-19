#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//==========================================
class Fio
{
	string name;
	string middleName;
	string surname;

	Fio()
	{
		name;
		middleName;
		surname;
	}
	friend class Worker;
};
//==========================================
class Worker
{
	Fio worker;
	int number;
	double salary;
	static int count;
	int ID;
public:
	Worker()
	{
		count++;
		worker;
		number = 0;
		salary = 0;
		ID = count;
	}
	//--------------------------------------
	void setInfo()
	{
		cout << "============== �������� �" << ID << " ===============" << endl << endl;
		cout << "��� ���������:" << endl;
		cout << "���:";
		cin >> worker.name;
		cout << "��������:";
		cin >> worker.middleName;
		cout << "�������:";
		cin >> worker.surname;
		cout << "����� ������:";
		cin >> number;
		cout << "�����:";
		cin >> salary;
	}
	//--------------------------------------
	void getInfo()
	{
		cout << "============== �������� �" << ID << " ===============" << endl << endl;
		cout << "��� ���������: " << worker.surname << " " << worker.name << " " << worker.middleName << endl;
		cout << "����� ������: " << number << endl;
		cout << "�����: " << salary << endl;
	}
	//--------------------------------------
	string getSurname() const
	{
		return worker.surname;
	}
	void setSurname(string surname)
	{
		worker.surname = surname;
	}
	//--------------------------------------
	string getName() const
	{
		return worker.name;
	}
	void setName(string name)
	{
		worker.name = name;
	}
	//--------------------------------------
	string getMiddleName() const
	{
		return worker.middleName;
	}
	void setMiddleName(string middleName)
	{
		worker.middleName = middleName;
	}
	//--------------------------------------
	bool searchByNumber(int* number)
	{
		return (this->number == *number);
	}
	//--------------------------------------
	void salarySort(int* ID)
	{
		this->ID = *ID + 1;
	}
	//--------------------------------------
	void setID(int ID)
	{
		this->ID = ID;
	}
	int getID()
	{
		return ID;
	}
	//--------------------------------------
	void setNumber(int number)
	{
		this->number = number;
	}
	int getNumber()
	{
		return number;
	}
	//--------------------------------------
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	double getSalary()
	{
		return salary;
	}
};
//==========================================
int Worker::count = 0;
//==========================================
bool operator ==(const Worker& worker, string surname)
{
	return (worker.getSurname() == surname);
}
//==========================================
istream& operator>> (istream& in, Worker& worker)
{
	worker.setInfo();
	return in;
}
//==========================================
void saveDataBase(vector <Worker>& workman, int* n)
{
	ofstream file_txt;
	file_txt.open("file.txt");

	file_txt << *n << endl;
	for (int i = 0; i < *n; i++)
	{
		file_txt << workman[i].getID() << endl;
		file_txt << workman[i].getSurname() << endl;
		file_txt << workman[i].getName() << endl;
		file_txt << workman[i].getMiddleName() << endl;
		file_txt << workman[i].getNumber() << endl;
		file_txt << workman[i].getSalary() << endl;
	}
	file_txt.close();
}
//==========================================
int loadDataBase(vector <Worker>& workman)
{
	ifstream file_txt;
	file_txt.open("file.txt");
	if (!(file_txt.is_open()))
		return 0;
	else
	{
		int size = 0;
		file_txt >> size;
		workman.resize(size);
		for (int i = 0; i < size; i++)
		{
			int ID;
			file_txt >> ID;
			workman[i].setID(ID);

			string surname;
			file_txt >> surname;
			workman[i].setSurname(surname);

			string name;
			file_txt >> name;
			workman[i].setName(name);

			string middleName;
			file_txt >> middleName;
			workman[i].setMiddleName(middleName);

			int number;
			file_txt >> number;
			workman[i].setNumber(number);

			int salary;
			file_txt >> salary;
			workman[i].setSalary(salary);
		}
		file_txt.close();
		return size;
	}
}
//==========================================
void database(vector <Worker>& workman, int* n)
{
	if (*n != 0)
	{
		cout << "���� ������ ���������" << endl;
	}
	else
	{
		cout << "������� ���-�� ����������:";
		cin >> *n;
		workman.resize(*n);
		for (int i = 0; i < *n; i++)
		{
			workman[i].setInfo();
		}
	}
}
//==========================================
void menu(vector<Worker>& workman, int* n)
{
	for (int menu = 0; menu != 7;)
	{
		system("cls");
		menu = 0;
		cout << "===========================================" << endl << endl;
		cout << "������� ������ � ��������� ����...........1" << endl;
		cout << "�������� ��������� � ����.................2" << endl;
		cout << "����� �� ������ ������....................3" << endl;
		cout << "���������� �� ����������� ������..........4" << endl;
		cout << "����� ���� ���������� � �������� ��������.5" << endl;
		cout << "�������� ��������� ����� ����������.......6" << endl;
		cout << "����� �� ���������........................7" << endl;
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			for (int i = 0; i < *n; i++)
			{
				workman[i].getInfo();
			}
			break;
		}
		case 2:
		{
			int N = *n + 1;
			workman.resize(N);
			workman[N - 1].setInfo();
			*n = N;
			break;
		}
		case 3:
		{
			int number = 0;
			do
			{
				cout << "������� ����� ������:";
				cin >> number;
			} while (number < 0 || number == 0);
			int tmp = 0;
			for (int i = 0; i < *n; i++)
			{
				if (workman[i].searchByNumber(&number))
				{
					workman[i].getInfo();
					tmp += 1;
				}
				if (tmp == 0 && (i + 1) == *n)
					cout << "-------------------------------------------" << endl << "������ ������ ������ ���" << endl;
			}
			break;
		}
		case 4:
		{
			for (int count = 0; count < *n; count++)
			{
				for (int i = 0; i < *n; i++)
				{
					int SmallestIndex = i;
					for (int j = i + 1; j < *n; j++)
					{
						if (workman[SmallestIndex].getSalary() < workman[j].getSalary())
							SmallestIndex = j;
					}

					workman[i].salarySort(&SmallestIndex);
					workman[SmallestIndex].salarySort(&i);

					swap(workman[i], workman[SmallestIndex]);
				}
			}
			cout << "�������������" << endl;
			break;
		}
		case 5:
		{
			string surname;
			cout << "������� �������:";
			cin >> surname;
			int tmp = 0;
			for (int i = 0; i < *n; i++)
			{
				if (workman[i] == surname)
				{
					workman[i].getInfo();
					tmp++;
				}
				if (tmp == 0 && (i + 1) == *n)
					cout << "-------------------------------------------" << endl << "������ ��������� ���" << endl;
			}
			break;
		}
		case 6:
		{
			int N;
			cout << "������� ���-�� �������:";
			cin >> N;
			N += *n;
			workman.resize(N);
			for (int i = *n; i < N; i++)
			{
				cin >> workman[i];
			}
			*n = N;
			break;
		}
		}
		system("pause");
	}
}
//==========================================
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	vector <Worker> workman(n);
	n = loadDataBase(workman);

	database(workman, &n);
	menu(workman, &n);
	saveDataBase(workman, &n);
	return 0;
}