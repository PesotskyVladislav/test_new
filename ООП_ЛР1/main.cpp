#include "calc.h"
#define LIBAPP_CALC_HPP

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(void) {

	setlocale(LC_CTYPE, ".1251");

	enum err_expr e;
	char          s[256];
	double        t, res;

	cout << "������� �������������� ���������" << endl;
	cin >> s;
	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		printf("%lg\n\n", res);
		break;
	case ERR_NONE_STR:
		puts("������ �����!");
		break;
	case ERR_DIV_BYZERO:
		puts("������� �� ����!");
		break;
	case ERR_PARSE_NUMBER:
		puts("������ ��� ������������ ���������.");
		break;
	case ERR_EXPR:
		puts("������������� �� ���������� ���������! ");
		break;
	}
	getchar();
	system("pause");
	return 0;
}