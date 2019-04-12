#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void choise(char *func) {
	if ( strstr(func, "DUP") ) {
		cout << "DUP\n";
	} else if ( strstr(func, "MUL") ) {
		cout << "MUL\n";
	} else if ( strstr(func, "SWAP") ) {
		cout << "SWAP\n";
	} else if ( strstr(func, "ADD") ) {
		cout << "ADD\n";
	} else if ( strstr(func, "OWER")) {
		cout << "OWER\n";
	} else if ( strstr(func, "SIN")) {
		cout << "SIN\n";
	} else if ( strstr(func, "COS")) {
		cout << "COS\n";
	} else {
		cout << "INCORECT ENTER!";
	}
}
void function(char *str) {
	char *func;
	func = new char[20];
	for (int i = 0, k = 0; i <= (int)strlen(str); i++, k++) {
		if (str[i] == ' ' || str[i] == '\0') {
			choise(func);
			k = 0;
		} else {
			func[k] = str[i];
		}
	}
}
int main() {
	char *func_arr[20];
	function(func_arr);
}
/*---------------*/