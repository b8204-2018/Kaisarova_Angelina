#include "pch.h"
#include <iostream>

int main() {
	int a, b;
	int *p1, *p2;
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);
	p1 = &a;
	p2 = &b;
	*p2 = *p1 + *p2;
	*p1 = *p2 - *p1;
	*p2 = *p2 - *p1;
	printf("%s%d%s%d", "a = ", a, " b = ", b);

}
