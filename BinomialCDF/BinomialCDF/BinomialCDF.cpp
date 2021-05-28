#include<stdio.h>
#include <math.h>
#include <graphics.h> 
#include <conio.h>
#include <iostream> 

double p;
double n;
double array[100] = { 0.0 };


void BINCDF(double, double);
double C(double, double);
double factorial(double);
void graph(void);

void main() {
	puts("CDF : ");

	printf("輸入p的機率 :");
	scanf_s("%lf", &p);

	printf("輸入n :");
	scanf_s("%lf", &n);


	BINCDF(p, n);
	system("pause");
	graph();
}

void BINCDF(double p, double n) {
	double CDF = 0.0;
	int j = 0;
	double i = 0.0;
	for (i = 0.0, j = 0; i <= n; i++, j++) {
		CDF = CDF + C(n, i) * pow(p, i) * pow((1 - p), (n - i));
		printf("x = %lf		Fx(X) = %lf \n", i, CDF);
		array[j] = CDF;
	}
}

double factorial(double x) {
	double k = 1.0;
	for (double i = 1.0; i <= x; i++) {
		k *= i;
	}
	return k;
}

double C(double n, double x) {
	return factorial(n) / (factorial(x) * factorial(n - x));
}

double pow2(double a, double b) {
	return a * b;
}

void graph(void) {
	double temp = 950 / n;
	initgraph(1050, 550);
	line(50, 50, 50, 500);
	line(50, 500, 1000, 500);
	for (int i = 0; i < (int)n; i++) {
		circle(i * temp + 50, 500 - array[i] * 400, 1.5);
	}
	system("pause");
	closegraph();
}