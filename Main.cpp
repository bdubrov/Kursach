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
#include <cstdio>
using namespace std;
class stack {
	double *stck;
	int tos;
public:
	stack(double x);
	~stack();
	void push(double x);
	double pop();
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
	stck = (double *)realloc(stck, tos + 1);
	if (!stck) {
		cout << "Allocation Error!";
	}
	stck[tos] = x;
	tos++;
}
double stack::pop() {
	if(tos == 0){
		cout << "Stack is empty";
		return 0;
	}
	stck = (double *)realloc(stck, tos - 1);
	if (!stck) {
		cout << "Allocation Error!";
	}
	tos--;
	return stck[tos];
}
void DUP(stack &s) {
	double tmp = s.pop();
	s.push(tmp);
	s.push(tmp);
}
void MUL(stack &s) {
	double x1, x2, mult;
	x1 = s.pop();
	x2 = s.pop();
	mult = x1 * x2;
	s.push(mult);
}
void SWAP(stack &s) {
	double x1, x2;
	x1 = s.pop();
	x2 = s.pop();
	s.push(x1);
	s.push(x2);
}
void ADD(stack &s) {
	double x1, x2, add;
	x1 = s.pop();
	x2 = s.pop();
	add = x1 + x2;
	s.push(add);
}
void OVER(stack &s) {
	double x1, x2;
	x1 = s.pop();
	x2 = s.pop();
	s.push(x2);
	s.push(x1);
	s.push(x2);
}
void SIN(stack &s) {
	double x = sin(s.pop());
	s.push(x);
}
void COS(stack &s) {
	double x = cos(s.pop());
	s.push(x);
}
void choice(char *func, stack &s) {
	if ( strstr(func, "DUP") ) {
		DUP(s);
	} else if ( strstr(func, "MUL") ) {
		MUL(s);
	} else if ( strstr(func, "SWAP") ) {
		SWAP(s);
	} else if ( strstr(func, "ADD") ) {
		ADD(s);
	} else if ( strstr(func, "OVER")) {
		OVER(s);
	} else if ( strstr(func, "SIN")) {
		SIN(s);
	} else if ( strstr(func, "COS")) {
		COS(s);
	} else {
		cout << "INCORECT ENTER!";
		exit(-1);
	}
}
void function(char *str, stack &s) {
	char *func;
	func = new char[20];
	for (int i = 0, k = 0; i <= (int)strlen(str); i++, k++) {
		if (str[i] == ' ' || str[i] == '\0') {
			choice(func, s);
			k = 0;
		} else {
			func[k] = str[i];
		}
	}
}
void print(char *arr) {
	char ch;
	int n = 0; 
	while ((ch = getchar())!= '\n') {
		arr = (char *)realloc(arr, sizeof(arr)+1);
		arr[n] = ch;
		n++;
	}
}
void instruction() {
	cout<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|Опервция|                        Назначение                        |\n"<<
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
	"     Введите команды через пробел (нажмите ENTER для выполнения)     \n";
}
int main() {
	char *func_arr;
	func_arr = (char *)malloc(sizeof(char));
	instruction();
	print(func_arr);
	for (int i = -5; i <= 5; i++){
		stack s(i);
		function(func_arr, s);
		cout << "x=" << i << " y=" << s.pop();
		cout << endl;
	}
	return 0;
}
/* ---------------------------------------------------------------------[<]-
Test1 output:
---------------------------------------------------------------------[>]-*/