// tiaoshi1.cpp: 定义控制台应用程序的入口点。
//
#include <cstdio>
#include "stdafx.h"//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define init_stack 10;
#define error "程序错误"
typedef struct stack //栈的结构
{
	char *top;
	char *base;
	int size;
}stack;
int initstack(stack &s)//建栈
{
	s.base = (char *)malloc(100 * sizeof(char));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.size = 10;
	return 0;
}
int push(stack &s, char e)//插入栈顶元素
{
	if (s.top - s.base > s.size)
	{
		s.base = (char*)realloc(s.base, (s.size + 100) * sizeof(char));
		if (!s.base) {
			return -1;
		}
		s.top = s.base + s.size;
		s.size += 10;
	}
	*s.top = e;
	s.top++;
	return 0;
}
int Pop(stack &s, char &e)//删除栈顶元素
{
	if (s.top == s.base) {
		return -1;
	}
	e = *--s.top;
	return 0;
}
char Gettop(stack s)//得到栈顶元素
{
	if (s.top == s.base) {
		return -1;
	}
	return *(s.top - 1);
}
char Precede(char t, char k2)//比较运算符大小
{
	switch (k2) {
	case '+':
		if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '-':
		if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '*':
		if (t == '*' || t == '/') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '/':
		if (t == '*' || t == '/') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '(':
		return '<';
	case ')':
		if (t == '(') {
			return '=';
		}
		else {
			return'>';
		}
	case '#':
		if (t == '#') {
			return '=';
		}
		else {
			return '>';
		}
	default:
		printf("error in precede");
		break;
	}
	return 0;
}
int In(char c)//判断是否是运算符
{
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return 1;
		break;
	}
	return 0;
}
char Operate(char a, char theta, char b)
{
	int x, y;
	char c;
	x = 0; y = 0;
	x = a - '0';
	y = b - '0';
	switch (theta) {
	case '+':c = x + y;
		return c;
	case '-':c = x - y;
		return c;
	case '*':c = x * y;
		return c;
	case '/':
		if (y == 0)
			printf("除数不能为0");
		c = x / y;
		return c;
		break;

	default:
		break;
	}
	return 0;
}
char EvaluateExpression(char a[])
{

	int i;
	char e, h;
	e = '#';
	stack OPND, OPTR;
	initstack(OPTR);
	push(OPTR, e);
	initstack(OPND);
	char c, x, d, b, theta;
	c = a[0];
	for (i = 1; c != '#' || Gettop(OPTR) != '#'; i++)
	{
		if (0==In(c))
		{
			push(OPND, c);
			c = a[i];
		}
		else {
			switch (Precede(Gettop(OPTR), c))
			{
			case '<':
				push(OPTR, c); c = a[i];
				break;
			case '=':
				Pop(OPTR, x); c = a[i];
				break;
			case '>':
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, d);
				push(OPND, Operate(d, theta, b));
				break;
			}
		}
	}
	return Gettop(OPND);
	//return c;
}
int main()
{
	char a[10], b;
	int c;
	printf("请输入表达式\n");
	scanf_s("%s", a, 10);
	b = EvaluateExpression(a);
	c = b;
	printf("输出为%d\n",c);
}
