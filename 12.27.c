#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
typedef struct stackArray
{
	int* data;
	int num;
	size_t max_size;
}stackarray;
//
void Initstack(stackarray* s, size_t size)
{
	s->data = (char*)malloc(size * sizeof(char));
	s->max_size = size;
	s->num = 0;
}

int stackempty(stackarray* s)
{
	if (s->num == 0)
		return 1;
	return 0;
}
void push(stackarray* s, const int n)
{
	assert(s->num < s->max_size);
	s->data[s->num] = n;
	s->num += 1;
}
int pop(stackarray* s)
{
	assert(s->num);
	int a = s->data[s->num-1];
	s->num -= 1;
	return a;
}

void destroy(stackarray* s)
{
	free(s->data);
}
bool isValid(char* str) {
	stackarray s;
	int a = 0;
	int b = strlen(str);
	Initstack(&s, b);
	while (str[a])
	{
		if (str[a] == '{' || str[a] == '[' || str[a] == '(')
		{
			push(&s, str[a]);
			a++;
			continue;
		}
		else {
			if (stackempty(&s)) {
				return false;
			}
			char m = pop(&s);
			if ((str[a] == '}' && m == '{') || (str[a] == ')' && m == '(') || (str[a] == ']' && m == '['))
			{
				a++;
				continue;
			}
			else {
				return false;
			}
		}
	}
	if (!stackempty(&s))
	{
		return false;
	}
	return true;
}
int main()
{
	stackarray s;
	int a = 0;
	char str[1000] = "";
	gets(str);
	printf("%d", isValid(str));
}
	//int b = strlen(str);
	//Initstack(&s, b);
	//while (str[a])
	//{
	//	if (str[a] == '{' || str[a] == '[' || str[a] == '(')
	//	{
	//		push(&s, str[a]);
	//		a++;
	//		continue;
	//	}
	//	else {
	//		if (stackempty(&s)) {
	//			printf("false");
	//			return 0;
	//		}
	//		char m = pop(&s);
	//		if ((str[a]=='}'&&m=='{')||(str[a]==')'&&m=='(')||(str[a]==']'&&m=='['))
	//		{
	//			a++;
	//			continue;
	//		}
	//		else {
	//			printf("false");
	//				return 0;
	//		}
	//	}
	//}
	//if (!stackempty(&s))
	//{
	//	printf("false");
	//}
	//else
	//	printf("true");
	//return 0;