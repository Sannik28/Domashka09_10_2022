// Domashka09_10_2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Zanyatie09_10_22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include <string>



using namespace std;

void inline Print(int** arr, int strok, int stolb) {
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void inline Delete(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		delete[]arr[i];
	}
	delete[]arr;
}

//Задание 1.Написать функцию,добавляющую столбец двумерному массиву в указанную позицию


void f1(int** arr2, int stolb, int strok, int poz) {
	int s = 9;
	int** new_arr2 = new int* [strok];
	for (int i = 0; i < strok; i++) {
		new_arr2[i] = new int[stolb+1];
	}
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb+1; j++) {
			if (j < poz) {
				new_arr2[i][j] = arr2[i][j]; 
				//cout << new_arr2[i][j]<< " ";
			}
			else if (j == poz) {
				new_arr2[i][j] = s;
			//	cout << new_arr2[i][j] << " ";
			}
			else { new_arr2[i][j] = arr2[i][j - 1];
			//cout << new_arr2[i][j] << " "; 
			}
	}
		cout << endl;
}
	Delete(arr2, strok);
	Print(new_arr2, strok, stolb+1);
}

void f2(int** arr2, int stolb, int strok, int poz) {
	int s = 9;
	int** new_arr2 = new int* [strok];
	for (int i = 0; i < strok; i++) {
		new_arr2[i] = new int[stolb - 1];
	}
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++) {
			if (j < poz) {
				new_arr2[i][j] = arr2[i][j];
				//cout << new_arr2[i][j]<< " ";
			}
			else if (j > poz) {
				new_arr2[i][j-1] = arr2[i][j];
				//cout << new_arr2[i][j-1] << " ";
			}
		}
		//cout << endl;
	}
	Delete(arr2, strok);
	Print(new_arr2, strok, stolb - 1);
}
//сдвиг позиций матрицы вверх вниз вправо влево
void f3(int** arr2, int n, int m, int kol, int napr) {
	int** new_arr2 = new int* [m];
	for (int i = 0; i < m; i++) {
		new_arr2[i] = new int[n];
	}
	int k = 1;
	do{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (napr == 6) {
					if (j!=0)
						new_arr2[i][j] = arr2[i][j-1];
					else
						new_arr2[i][j] = arr2[i][n - 1];
				}
				if (napr == 4) {
					if (j != n - 1)
						new_arr2[i][j] = arr2[i][j + 1];
					else
						new_arr2[i][j] = arr2[i][0];
				}
				if (napr == 8) {
					if (i != m-1)
						new_arr2[i][j] = arr2[i + 1][j];
					else
						new_arr2[i][j] = arr2[0][j];
				}
				if (napr == 2) {
					if (i != 0)
						new_arr2[i][j] = arr2[i - 1][j];
					else
						new_arr2[i][j] = arr2[m-1][j];
				}
			}
			
		
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				arr2[i][j] = new_arr2[i][j];
		}
		k++;
	} while (k <= kol);
	Delete(arr2, m);
	Print(new_arr2, m, n);
}
//транспонирование матрицы
void f4(int** arr2, int n, int m) {
	int** new_arr2 = new int* [n];
	for (int i = 0; i < n; i++) {
		new_arr2[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr2[i][j] = arr2[j][i];
		}
	}
	
	Delete(arr2, m);
	Print(new_arr2, n, m);
}
//имя и телефон с поиском вариант 1 не работает на строке cout << strlen(arr[1]) << endl;
/* неудачная попытка ;(
void f5name(string** arr, char* name) {
	int cout = 0;
	int n;
	string tel;
		for (int i = 0; i < 3; i++) {
			if (arr[1][i]== name) {
				cout << "Телефон данного абонента ";
				tel= arr[2][i];
				cout << tel;
				n = i;
				cout++;
			}
		}
		if (cout == 0) 
			cout << "Абонент не найден.";
		if (cout > 0) {
			cout << "Внесите изменения в имя абонента " << name << " " << tel << " ";
			cin.getline(name, 80, '\n');
			arr[1][n] = name;
			cout << "Внесите изменения в телефон абонента " << name << " " << tel << " ";
			cin.getline(tel, 80, '\n');
			arr[2][n] = name;
		}
	}

void f5tel(string** arr, char* tel) {
	int cout = 0;
	int n;
	for (int i = 0; i < 3; i++) {
		if (arr[2][i] == tel) {
			cout << "Телефон принадлежит абоненту ";
			cout << arr[1][i];
			n = i;
			cout++;
		}
		
	}
	if (cout == 0) { cout << "Указанный телефон не найден в базе данных."; }
	if (cout > 0) {
		cout << "Внесите изменения в имя абонента " << name << " " << tel << " ";
		cin.getline(name, 80, '\n');
		arr[1][n] = name;
		cout << "Внесите изменения в телефон абонента " << name << " " << tel << " ";
		cin.getline(tel, 80, '\n');
		arr[2][n] = name;
	}
}

	//Delete(arr2, m);
	//Print(new_arr2, n, m);
}
*/
void searchByName(char** arr, const char* name) 
{
	//массив для хранения искомого имени и телефона
	char** info = new char* [2];
	info[0] = new char[strlen(name) + 1];
	info[1] = new char[16];
	//стартовое и конечное положение в массиве
	int start = strlen(arr[0]) - strlen(strstr(arr[0], name));
	//cout << "1. " << strstr(arr[0], name)<<endl; //при поиске Смирнова выдает Смирнов, Петров первое вхождение
	//cout << "2. "<<strlen(strstr(arr[0], name)) << endl;//15 - измеряем длину строки от начала Смирнова
	//cout << "3. " << start << endl; //8- количество знаков до Смирнова
	int end;
	if (strchr(arr[0] + start, ',') != 0) {//если Смирнов не в конце, после него стоит ','
		//cout << endl<< "4. " << strchr(arr[0] + start, ','); //  , Петров мы нашли где Смирнов заканчивается
		end = strlen(arr[0]) - strlen(strchr(arr[0] + start, ','));//Нашли количество символов после Смирнова
		//cout << endl << "5. " << arr[0] - strchr(arr[0] + start, ',');
	}

	else
		end = strlen(arr[0]);//если фамилия в конце то конец знаков после искомой фамилии-все знаки
	//копирование имени в новый масиив
	strncpy_s(info[0], end - start + 1, arr[0] + start, end - start);//куда копируем, количество резервируемых символов, откуда, количество
	 // поиск и копирвоание соответствующего имени номера телефона
	int c = 0, i = 0;
	while (i < start - 1 && strchr(arr[0] + i, ',') != 0) {//считаекм количество запятых до старта
		i = strlen(arr[0]) - strlen(strchr(arr[0] + i, ',')) + 1;//увеличиваем i до знака после запятой
		c++;
	}
	strncpy_s(info[1], 16, arr[1] + 17 * c, 15);//15- количество символов номера телефона копируем в массив info телефон искомого абонента
	cout << info[1];
	}


char** searchByTel(char** arr, const char* tel)
{
	char** info = new char* [2];
	info[0] = new char[17];
	info[1] = new char[17];
	int start = strlen(arr[1]) - strlen(strstr(arr[1], tel));
	cout << strstr(arr[1], tel) << endl;
	cout << strlen(arr[1]) << endl;
	cout << strlen(strstr(arr[1], tel)) << endl;
	cout << strlen(arr[1]) << endl;
	int end=15;
	strncpy_s(info[1], 16, arr[1] + start, 15);
	int c, k=0;
	c = start / 17; //какой по счету номер-имя
	int st, en;
	int i=0;
	while (i < start - 1 && strchr(arr[0] + i, ',') != 0) {//считаекм количество запятых до старта
		i = strlen(arr[0]) - strlen(strchr(arr[0] + i, ',')) + 1;//увеличиваем i до знака после запятой
		k++;
		if (c == k) {
			st = i;
		}
		if (c-1==k) {
			en = i;
	}
	strncpy_s(info[0], en - st + 1, arr[0] + st, en - st);
	cout << info[0];

	}
	return info;

}

char** searchByName2(char** arr, const char* name) {
	char** info = new char* [2];
	info[0] = new char[strlen(name)];
	info[1] = new char[17];
	for (int i = 0; i < 6; i += 2) {
		if (strcmp(arr[i], name) == 0) { //сравниваем символы массивов
			strcpy_s(info[0], strlen(arr[i]) + 1, arr[i]);//копируем фамилию
			strcpy_s(info[1], strlen(arr[i + 1]) + 1, arr[i + 1]);//копируем телефон
			break;
		}
	}
	cout << info[0] << " " << info[1];
return info;
}

char** searchByTel2(char** arr, const char* tel) {
	char** info = new char* [2];
	info[1] = new char[17];
	for (int i = 1; i <= 6; i += 2) {
		if (strcmp(arr[i], tel) == 0) { //сравниваем символы массивов
			info[0] = new char[strlen(arr[i]) + 1];
			strcpy_s(info[0], strlen(arr[i]) + 1, arr[i]);//копируем телефон
			strcpy_s(info[1], strlen(arr[i - 1]) + 1, arr[i - 1]);//копируем фамилию
			break;
		}
	}
	cout << info[0] << " " << info[1];
	return info;
}

//структура автомобиль (длина клиренс,объем двиг, мощн, диам, цвет, коробка
struct Avto {
	string marka;
	struct {
		int l;
		int h;
		int Vd;
		int P;
		int d;
		string color;
		string korobka;
	}avtom;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//задания 1 и 2);
	/*
	int stolb = 5;
	int strok = 2;
	int poz = 3;
	int** arr2 = new int* [strok];
	for (int i = 0; i < strok; i++) {
		arr2[i] = new int[stolb];
	}
	for (int i = 0; i < strok; i++) {
		for (int j = 0; j < stolb; j++) {
			arr2[i][j] = i * 2;
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	//f1(arr2, stolb, strok, poz);
	f2(arr2, stolb, strok, poz);
	*/
	/*
	//задание 3
	int n = 5;//столбцов
	int m = 4;//cтрок
	int kol = 2;
	int napr;
	cout << "napr=";
	cin >> napr; //указываем направление 4 влево 6 вправо 8 вверх 2 вниз
	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++) {
		arr2[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = (i+j) * 2;
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	f3(arr2, n, m, kol, napr);
	*/
	//задание 4
	/*
	int n = 5;//столбцов
	int m = 4;//cтрок
	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++) {
		arr2[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = (i + j) * 2;
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	f4(arr2, n, m);
	*/
	
	//задание 5 имя и телефон с поиском
	/*
	//безуспешная попытка решить задачку
	string** arr = new string * [2];
	char name[80], tel[80];
	for (int i = 0; i < 3; i++) {
		arr[i] = new string[3];
	}
	//char* arr2 = new char[3];
	for (int i = 0; i < 3; i++) {
		cout << i<<" Введите имя \n";
		cin.getline(name,80,'\n');
		arr[1][i] = name;
		cout << i << " Введите телефон \n";
		cin.getline(tel, 80, '\n');
		arr[2][i] = tel;
	}
	cout << "Поиск по абоненту\nВведите искомого абонента\n";
	cin.getline(name, 80, '\n');
	f5name(arr, name);
	cout << "Поиск по номеру телефона\nВведите номер телефона\n";
	cin.getline(tel, 80, '\n');
	f5tel(arr, tel);
	*/
	//1 вариант попытка не удачная. Что не так-не понятно. Что-то с размерами массивов и выводом размера строки arr[1]
	/*
	char** info = new char* [2];
	info[0] = new char[255]{ "Иванов, Смирнов, Петров" };
	info[1] = new char[255]{ "+7111-111-11-11, +7222-222-22-22, +7333-333-33-33" };
	cout << "Осуществить поиск 1 - телефона по фамилии 2 - фамилии по номеру телефона 3 - выход" << endl;
	int vib;
	cin >> vib;
	do {
		if (vib == 1) {
			char* name = new char[255];
			cout << "Введите фамилию абонента\n";
			cin.ignore();
			gets_s(name, strlen(name));
			//gets_s(name, 255);
			searchByName(info, name);
		}
		else if (vib == 2) {
			char* tel = new char[255];
			cout << "Введите телефон абонента\n";
			cin.ignore();
			gets_s(tel, strlen(tel));
			searchByTel(info, tel);
		}
	} while (vib != 3);
	*/
	// 2 вариант
	char** info = new char* [6];
	info[0] = new char[255]{ "Иванов"};
	info[1] = new char[255]{ "+7111-111-11-11" };
	info[2] = new char[255]{ "Смирнов" };
	info[3] = new char[255]{ "+7222-111-11-11" };
	info[4] = new char[255]{ "Сидоров" };
	info[5] = new char[255]{ "+7333-111-11-11" };
	int vib;
	do {
	cout << "Осуществить поиск 1 - телефона по фамилии 2 - фамилии по номеру телефона 3 - выход" << endl;
	cin >> vib;
		if (vib == 1) {
			char* name = new char[100];
			cout << "Введите фамилию абонента\n";
			cin.ignore();
			gets_s(name, strlen(name));
			//gets_s(name, 255);
			searchByName2(info, name);
		}
		else if (vib == 2) {
			char* tel = new char[17];
			cout << "Введите телефон абонента\n";
			cin.ignore();
			gets_s(tel, strlen(tel));
			searchByTel2(info, tel);
		}
	} while (vib != 3);
	
	/*
	Avto Lada = { "Lada ",11,12,13, 14, 15, {"Blue"},{"robot"}};
	Avto Opel = { "Opel ",21,22,23, 24, 25, {"Black"},{"ruchn"} };
	Avto Lexus = { "Lexus ",31,32,33, 34, 35, {"Yellow"},{"auto"} };
	*/
}
	
/*
	arr**[0] = new char[256] {"Hello "};
	arr[1] = new char[256] {"my "};
	arr[2] = new char[256] {"friend "};
	char* str = new char[256] {"and goodbye"};
	//arr = f1(arr, str);
	*/



		// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
		// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

		// Советы по началу работы 
		//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
		//   2. В окне Team Explorer можно подключиться к системе управления версиями.
		//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
		//   4. В окне "Список ошибок" можно просматривать ошибки.
		//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
		//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
