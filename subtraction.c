#include <stdio.h>

int sub()
{
	int a, b;
	
	printf("[C] Enter first number: ");
	scanf("%d", &a);
	
	printf("[C] Enter second number: ");
	scanf("%d", &b);
	
	int result = a - b;
	printf("[C] The total is: %d\n", result);
	
	return result;
}
