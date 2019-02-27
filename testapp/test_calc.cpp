#include "calc.h"
#include <cmath>
#include <gtest\gtest.h>
#include <iostream>



TEST(libapp, TEST1)
{
	enum err_expr e;
	char t[50];
	char s[] = "(";
	double res;

	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		break;
	case ERR_NONE_STR:
		strcpy_s(t, "Строка пуста!");
		break;
	case ERR_DIV_BYZERO:
		strcpy_s(t, "Деление на ноль!");
		break;
	case ERR_PARSE_NUMBER:
		strcpy_s(t, "Ошибка при парсировании выражения.");
		break;
	case ERR_EXPR:
		strcpy_s(t, "Арифметически не корректное выражение!");
		break;
	}

	ASSERT_STREQ(t, "Арифметически не корректное выражение!");
}

TEST(libapp, TEST2)
{
	enum err_expr e;
	char t[50];
	char s[] = "2/0";
	double res;

	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		break;
	case ERR_NONE_STR:
		strcpy_s(t, "Строка пуста!");
		break;
	case ERR_DIV_BYZERO:
		strcpy_s(t, "Деление на ноль!");
		break;
	case ERR_PARSE_NUMBER:
		strcpy_s(t, "Ошибка при парсировании выражения.");
		break;
	case ERR_EXPR:
		strcpy_s(t, "Арифметически не корректное выражение!");
		break;
	}

	ASSERT_STREQ(t, "Деление на ноль!");
}

TEST(libapp, TEST3)
{
	enum err_expr e;
	char t[50];
	char s[] = "10a*5";
	double res;

	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		break;
	case ERR_NONE_STR:
		strcpy_s(t, "Строка пуста!");
		break;
	case ERR_DIV_BYZERO:
		strcpy_s(t, "Деление на ноль!");
		break;
	case ERR_PARSE_NUMBER:
		strcpy_s(t, "Ошибка при парсировании выражения.");
		break;
	case ERR_EXPR:
		strcpy_s(t, "Арифметически не корректное выражение!");
		break;
	}

	ASSERT_STREQ(t, "Ошибка при парсировании выражения.");
}


TEST(libapp, TEST4)
{
	enum err_expr e;
	char t[50];
	char s[] = "(f)";
	double res;

	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		break;
	case ERR_NONE_STR:
		strcpy_s(t, "Строка пуста!");
		break;
	case ERR_DIV_BYZERO:
		strcpy_s(t, "Деление на ноль!");
		break;
	case ERR_PARSE_NUMBER:
		strcpy_s(t, "Ошибка при парсировании выражения.");
		break;
	case ERR_EXPR:
		strcpy_s(t, "Арифметически не корректное выражение!");
		break;
	}

	ASSERT_STREQ(t, "Ошибка при парсировании выражения.");
}

TEST(libapp, TEST5)
{
	enum err_expr e;
	char t[50];
	char s[] = "(2)h";
	double res;

	res = calculate(s, &e);
	switch (e) {
	case ERR_SUCCESS:
		break;
	case ERR_NONE_STR:
		strcpy_s(t, "Строка пуста!");
		break;
	case ERR_DIV_BYZERO:
		strcpy_s(t, "Деление на ноль!");
		break;
	case ERR_PARSE_NUMBER:
		strcpy_s(t, "Ошибка при парсировании выражения.");
		break;
	case ERR_EXPR:
		strcpy_s(t, "Арифметически не корректное выражение!");
		break;
	}

	ASSERT_STREQ(t, "Арифметически не корректное выражение!");
}


TEST(libapp, TEST6)
{
	char s[] = "2+2";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 4);
}

TEST(libapp, TEST7)
{
	char s[] = "2*(2-2)";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 0);
}


TEST(libapp, TEST8)
{
	char s[] = "(2)";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 2);
}

TEST(libapp, TEST9)
{
	char s[] = "(2-2)";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 0);
}

TEST(libapp, TEST10)
{
	char s[] = "(2*2)";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 4);
}

TEST(libapp, TEST11)
{
	char s[] = "(2/2)";
	double res;

	res = calculate(s, NULL);
	ASSERT_EQ(res, 1);
}
