//#include <iostream>
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
    s.base=(char *)malloc(100*sizeof(char));
    if (!s.base)
        return -1;
        s.top=s.base;
    s.size=10;
    return 0;
}
int push(stack &s,char &e)//插入栈顶元素
{
    if (s.top==s.base)
    {
        s.base=(char*)realloc(s.base,(s.size+100)*sizeof(char));
        if (!s.base) {
            return -1;
        }
        s.top=s.base+s.size;
        s.size+=10;
    }
    *s.top++=e;
    return 0;
}
int Pop(stack &s,char &e)//删除栈顶元素
{
    if (s.top==s.base) {
        return -1;
    }
    e=*--s.top;
    return 0;
}
int Gettop(stack s,char &e)//得到栈顶元素
{
    if (s.top==s.base) {
        return -1;
    }
    e=*(s.top-1);
    return 0;
}
char Precede(char t,char k2)//比较运算符大小
{
    switch (k2) {
        case '+':
            if (t=='+'||t=='-'||t=='*'||t=='/'||t==')') {
                return '>';
            } else {
                return '<';
            }
            break;
        case '-':
            if (t=='+'||t=='-'||t=='*'||t=='/'||t==')') {
                return '>';
            } else {
                return '<';
            }
            break;
        case '*':
            if (t=='*'||t=='/') {
                return '>';
            } else {
                return '<';
            }
            break;
        case '/':
            if (t=='*'||t=='/') {
                return '>';
            } else {
                return '<';
            }
            break;
        case '(':
            return '<';
        case ')':
            if (t=='(') {
                return '=';
            } else {
                return'>';
            }
        case '#':
            if (t=='#') {
                return '=';
            } else {
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
int Operate(char a, char theta, char b)
{
    int x,y;
    x=0;y=0;
    x=a-'0';
    y=b-'0';
    switch (theta) {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            if (y==0)
                printf("除数不能为0");
                return x/y;
            break;
            
        default:
            break;
    }
    return 0;
}
char EvaluateExpression(char a[])
{
    stack OPND,OPTR;
    initstack(OPTR);
    push(OPTR,'#');
    initstack(OPND);
    char c,x,d,b,theta;
    c=a[0];
    for (i=0; c!='#'||Gettop(OPTR)!='#'; i++) {
        if (!In(c,OPND) {
            push(OPND,c);c=a[i];
        } else {
            switch(Precede(Gettop(OPTR),c))
            {
                case '<':
                    push(OPTR,c);c=a[i];
                    break;
                case '=':
                    Pop(OPTR,x);c=a[i];
                    break;
                case '>':
                    Pop(OPTR,theta);
                    Pop(OPTR,b);
                    Pop(OPTR,d);
                    push(OPND,Operate(a,theta,b));
                    break;
            }
        }
            }
            return Gettop(OPND);
            }
            int main()
        {
            char a[10],b[10];
            printf("请输入表达式\n")；
            scanf("%s",a);
            b[10]=EvaluateExpression(a[10]);
            printf("输出为%s",b[10]);
        }
            
            
            
            
            
            
            
            
            
            
