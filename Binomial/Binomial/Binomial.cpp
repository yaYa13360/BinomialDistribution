#include <stdio.h>
#include <math.h>
#include <graphics.h> 
#include <conio.h>
#include <iostream>

void BINCDF(double, double);
void BINPMF(double, double);
double PMFCount(double, double, double);
double C(double, double);
double factorial(double);
void graph(double, double[]);
void cleanData();
void countEx(double p, double n);
void countVarx(double p, double n);

double CDF[100] = { 0.0 };
double PMF[100] = { 0.0 };

void main() {
	double p;
	double n;
	int key = 1;
	while (key == 1) {
		cleanData();
		printf("¿é¤Jp : ");
		scanf_s("%lf", &p);

		printf("¿é¤Jn : ");
		scanf_s("%lf", &n);

		puts("PMF : ");
		BINPMF(p, n);
		system("pause");
		graph(n, PMF);

		system("pause");

		puts("CDF : ");
		BINCDF(p, n);
		system("pause");
		graph(n, CDF);

		printf("E[x] = ");
		countEx(p, n);
		printf("\nVar[x] = ");
		countVarx(p, n);
		system("pause");

		puts("(1)try again\t(2)exit");
		scanf_s("%d", &key);
	}
}

void countEx(double p, double n) {
	printf("%lf", n * p);
}
void countVarx(double p, double n) {
	printf("%lf", n * p * (1 - p));
}
void BINCDF(double p, double n) {
	double cdf = 0.0;
	int j = 0;
	double i = 0.0;
	for (i = 0.0, j = 0; i <= n; i++, j++) {
		cdf = cdf + C(n, i) * pow(p, i) * pow((1 - p), (n - i));
		printf("x = %lf		Fx(X) = %lf \n", i, cdf);
		CDF[j] = cdf;
	}
}

void BINPMF(double p, double n) {
	for (double i = 0.0; i <= n; i++) {
		PMF[(int)i] = PMFCount(i, n, p);
		printf("x = %lf, Px(x) = %lf\n", i, PMF[(int)i]);
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

double PMFCount(double x, double n, double p) {
	return(C(n, x) * pow(p, x) * pow(1.0 - p, n - x));
}

void graph(double n, double array[]) {
	double temp = 950 / n;
	initgraph(1050, 550);
	line(50, 50, 50, 500);
	line(50, 500, 1000, 500);
	for (int i = 0; i < (int)n; i++) {
		circle(i * temp + 50, 500 - array[i] * 400, 2);
		line(i * temp + 50, 500 - array[i] * 400, i * temp + 50, 500);
	}
	for (int k = 40; k <= 400; k += 40) {
		line(47, 500 - k, 53, 500 - k);
	}

	system("pause");
	closegraph();
}

void cleanData() {
	double CDF[100] = { 0.0 };
	double PMF[100] = { 0.0 };
}
