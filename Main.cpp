/* ----------------------------------------------------------------<Header>-
 Name: Main.cpp
 Group: TI-81
 Students: Slavskyy S.V., Dubrov B.Y.
 Written: 
 Revised: 
 Description:. 
    
 ------------------------------------------------------------------</Header>-*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <cstdio>
using namespace std;
class stack {
	double *stck;
	int tos;
public:
	stack(double x);
	~stack();
	void push(double x);
	bool pop(double &x);
	void show();
};
stack::stack(double x) {
	stck = (double *)malloc(sizeof(double));
	if(!stck) {
		cout << "Allocation Error!";
		exit(1);
	}
	stck[0] = x;
	tos = 1;
}
stack::~stack() {
	free(stck);
}
void stack::push(double x) {
	stck = (double *)realloc(stck, (tos + 1)*sizeof(double));
	if (!stck) {
		cout << "Allocation Error!";
	}
	stck[tos] = x;
	tos++;
}
bool stack::pop(double &x) {
	if(tos == 0){
		cout << "\nОШИБКА: недостаточно елементов для выполнения операции\n";
		cout << "Логически неверная запись функции\n\n";
		return false;
	}
	double d = stck[tos-1];
	tos--;
	stck = (double *)realloc(stck, tos*sizeof(double));
	if (!stck) {
		cout << "Allocation Error!";
	}
	x = d;
	return true;
}
bool DUP(stack &s) {
	double tmp;
	if (!s.pop(tmp)) {
		return false;
	}
	s.push(tmp);
	s.push(tmp);
	return true;
}
bool MUL(stack &s) {
	double x1, x2, mult;
	if (!s.pop(x1) || !s.pop(x2)) {
		return false;
	}
	mult = x1 * x2;
	s.push(mult);
	return true;
}
bool SWAP(stack &s) {
	double x1, x2;
	if (!s.pop(x1) || !s.pop(x2)) {
		return false;
	}
	s.push(x1);
	s.push(x2);
	return true;
}
bool ADD(stack &s) {
	double x1, x2, add;
	if (!s.pop(x1) || !s.pop(x2)) {
		return false;
	}
	add = x1 + x2;
	s.push(add);
	return true;
}
bool OVER(stack &s) {
	double x1, x2;
	if (!s.pop(x1) || !s.pop(x2)) {
		return false;
	}
	s.push(x2);
	s.push(x1);
	s.push(x2);
	return true;
}
bool SIN(stack &s) {
	double x;
	if (!s.pop(x)) {
		return false;
	}
	x = sin(x);
	s.push(x);
	return true;
}
bool COS(stack &s) {
	double x;
	if (!s.pop(x)) {
		return false;
	}
	x = cos(x);
	s.push(x);
	return true;
}
bool choice(char *func, stack &s) {
	bool tmp = true; 
	if ( strstr(func, "DUP") ) {
		tmp = DUP(s);
	} else if ( strstr(func, "MUL") ) {
		tmp = MUL(s);
	} else if ( strstr(func, "SWAP") ) {
		tmp = SWAP(s);
	} else if ( strstr(func, "ADD") ) {
		tmp = ADD(s);
	} else if ( strstr(func, "OVER")) {
		tmp = OVER(s);
	} else if ( strstr(func, "SIN")) {
		tmp = SIN(s);
	} else if ( strstr(func, "COS")) {
		tmp = COS(s);
	} else if ( strstr(func, "EXIT")) {
		exit(0);
	} else {
		cout << "\nОШИБКА: некоректный ввод!\n";
		cout << "Используйте только поданые ниже операции\n";
		tmp = false;
	}
	return tmp;
}
bool function(char *str, stack &s) {
	char func[20] = " ";
	// strcpy(func, " ");
	for (int i = 0, k = 0; i <= (int)strlen(str); i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			if(!choice(func, s)) {
				return false;
			}
			strcpy(func, "");
			k = 0;
		} else {
			func[k] = str[i];
			k++;
		}
	}
	return true;
}
char *read(char *arr) {
	char ch;
	int n = 0; 
	while ((ch = cin.get())!= '\n') {
		arr = (char *)realloc(arr, (strlen(arr)+1)*sizeof(char));
		arr[n] = ch;
		n++;
	}
	return arr;
}
void instruction() {
	cout<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|Операция|                        Назначение                        |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  DUP   |        Копировать верхний объект стека(A->AA)            |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  MUL   |      Перемножить два врхних елемента стека(5 2->10)      |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  SWAP  |   Поменять местами два верхних элемента стека (AB->BA)   |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  ADD   |        Сложить два верхних элемента стека (5 2->7)       |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  OVER  |Cкопироват второй сверху объект стека на вершину (AB->BAB)|\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  SIN   |   Заменить верхний обЪект строки на его синус (3.14->0)  |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
	"|  COS   |  Заменить верхний обЪект строки на его косинус (-3.14->0)|\n"<<
	"|-------------------------------------------------------------------|\n"<<
	"|  EXIT  |                   Выйти из программы                     |\n"<<
	"|-------------------------------------------------------------------|\n"<<
	"     Введите команды через пробел (нажмите ENTER для выполнения)     \n";
}
int main() {
	char *func_arr, *filename, ch, c;
	int k = 0, n = 0;
	double x1, x2, e;
	bool t = true;
	func_arr = (char *)malloc(sizeof(char));
	filename = (char *)malloc(sizeof(char));
	cout << "Введите название файла для записи(в формате .csv): ";
	while ((c = cin.get())!= '\n') {
		filename = (char *)realloc(filename, (strlen(filename)+1)*sizeof(char));
		filename[k] = c;
		k++;
	}
	ofstream file(filename);
	if ( !file ) {
		cout << "Can not open file: \"" << filename <<"\"" << endl;
		exit(1);
	} 
	cout << "Введите интервал построения графика\n";
		cout << "от: ";
		cin >> x1;
		cout << "до: ";
		cin >> x2;
		if (x2 < x1) {
			double temp = x1;
			x1 = x2;
			x2 = temp;
		}
		cout << "Введите точность построения: ";
		cin >> e;
		cin.ignore(256,'\n');
	file << "x;y" << endl;
	while(t) {
		instruction();
		while ((ch = cin.get())!= '\n') {
			func_arr = (char *)realloc(func_arr, (strlen(func_arr)+1)*sizeof(char));
			func_arr[n] = ch;
			n++;
		}
		for (int i = x1/e; i <= x2/e; i++){
			double x = i*e;
			stack s(x);
			if(!function(func_arr, s)) {
				t = true;
				break;
			} else {
				t = false;
				double y;
				s.pop(y);
				file << x << ";" << y << endl;
				cout << "x=" << x << " y=" << y;
				cout << endl;
			}
		}
	}
	file.close();
	ShellExecute(NULL, "open", "Excel.exe", filename , NULL, SW_SHOWMAXIMIZED);
	return 0;
}
