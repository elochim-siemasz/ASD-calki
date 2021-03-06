#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "calki.h"

#pragma warning(disable:4996)

double f1(double x)
{
	return x * pow(M_E, x);
}

double f2(double x)
{
	return pow(x, 3) + x;
}

double f3(double x)
{
	return cos(x);
}

double f4(double x)
{
	return 4 * x - 6 * pow(x, 2.0l / 3.0l);
}

int main(int argc, char *argv[])
{
	double od, do_;
	printf("od=");
	scanf("%lf", &od);
	printf("do=");
	scanf("%lf", &do_);
	setRange(od, do_);

	const int liczbaFunkcji = 4;
	void* funkcje[] = { f1, f2, f3, f4 };

	for (int i = 0; i < liczbaFunkcji; i++)
	{
		printf("funkcja %d:\n", i);
		printf("wynik prostokaty - %lf\n", prostokaty(funkcje[i]));
		printf("wynik trapezy    - %lf\n", trapezy(funkcje[i]));
		printf("wynik MC   - %lf\n\n", mc(funkcje[i]));
	}

	system("PAUSE");
	return 0;
}

