#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>

using namespace std;

int buf_size = 0;
int current_size = 0;

union number
{
	short int number_n;
	char number_s[20];
};

struct car
{
	char color[20];

	char model[20];

	char flag;

	number car_number;

	void print()
	{
		cout << color << " " << model << " ";

		if (flag == 's')
		{
			cout << car_number.number_s;
		}
		else
			cout << car_number.number_n;

		cout << endl;
	}


};

void add(car *&cs, car el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		cs = new car[buf_size];
	}
	else
	{
		if (buf_size == current_size)
		{
			buf_size *= 2;

			car* tmp = new car[buf_size];

			for (size_t i = 0; i < current_size; i++)
			{
				tmp[i] = cs[i];
			}
			delete[] cs;
			cs = tmp;
		}

	}

	cs[current_size++] = el;
}

void edit(car *cs, char flag)
{
	char number_s[10];
	short int number_n;

	int index = -1;

	if (flag == 's')
	{
		cout << "String number" << endl;
		cin >> number_s;

		for (size_t i = 0; i < current_size; i++)
		{
			if (!strcmp(number_s,cs[i].car_number.number_s))
			{
				index = i;
				break;
			}

		}

	}
	else
	{
		cout << "Enter numeric value" << endl;
		cin >> number_n;

		for (size_t i = 0; i < current_size; i++)
		{

			if (number_n == cs[i].car_number.number_n)
			{
				index = i; break;
			}

		}
	}



	if (index!=-1)
	{
		int choice;

		cout << "Enter 1 - to change color " << endl;

		cin >> choice;

		if (choice == 1)
		{
			cin >> cs[index].color;
		}

		cout << "Enter 2 - to change number " << endl;

		cin >> choice;

		if (choice == 2)
		{
			cout << "Enter number type: 's' for string and 'n' for numeric " << endl;

			cin >> cs[index].flag;

			cout << "Enter new number" << endl;

			if (cs[index].flag == 's')
			{
				cin >> cs[index].car_number.number_s;
			}
			else
				cin >> cs[index].car_number.number_n;

		}

	}

}

void edit(car *cs, char flag)
{
	char number_s[10];
	short int number_n;

	int index = -1;

	if (flag == 's')
	{
		cout << "String number" << endl;
		cin >> number_s;

		for (size_t i = 0; i < current_size; i++)
		{
			if (!strcmp(number_s, cs[i].car_number.number_s))
			{
				index = i;
				break;
			}

		}

	}
	else
	{
		cout << "Enter numeric value" << endl;
		cin >> number_n;

		for (size_t i = 0; i < current_size; i++)
		{

			if (number_n == cs[i].car_number.number_n)
			{
				index = i; break;
			}

		}
	}



	if (index != -1)
	{
		int choice;

		cout << "Enter 1 - to change color " << endl;

		cin >> choice;

		if (choice == 1)
		{
			cin >> cs[index].color;
		}

		cout << "Enter 2 - to change number " << endl;

		cin >> choice;

		if (choice == 2)
		{
			cout << "Enter number type: 's' for string and 'n' for numeric " << endl;

			cin >> cs[index].flag;

			cout << "Enter new number" << endl;

			if (cs[index].flag == 's')
			{
				cin >> cs[index].car_number.number_s;
			}
			else
				cin >> cs[index].car_number.number_n;

		}

	}

}

int search(car *cs, char flag) {

	char number_s[10];	short int number_n;	int index = -1;
	if (flag == 's') {
		cout << "String number" << endl;
		cin >> number_s;
		for (int i = 0; i < current_size; i++) {
			if (strcmp(cs[i].car_number.number_s, number_s) == 0)
			{
				index = i;
				break;
			}
		}
	}
	else
	{
		cout << "Numeric value" << endl;
		cin >> number_n;
		for (int i = 0; i < current_size; i++) {
			if (cs[i].car_number.number_n == number_n) {
				index = i;
				break;
			}
		}
	}
	return index;
}


int main()
{
	car *c = 0;
	car tmp_car;

	ifstream in_file("cars.txt");

	while (!in_file.eof())
	{
		in_file >> tmp_car.color >> tmp_car.model >> tmp_car.flag;

		if (tmp_car.flag == 's')
		{
			in_file >> tmp_car.car_number.number_s;
		}
		else
			in_file >> tmp_car.car_number.number_n;

		add(c, tmp_car);
	}

	for (size_t i = 0; i < current_size; i++)
	{
		c[i].print();
	}

	edit(c, 's');

	for (size_t i = 0; i < current_size; i++)
	{
		c[i].print();
	}

	system("pause");
	return 0;
}