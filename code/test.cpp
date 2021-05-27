#include <stdio.h>
#include <math.h>
#include <graphics.h>
double factorial(double);
double combination(double, double);
double PMFCount(double, double, double);

int main(){
	double n;
	double p;
	printf("---PMF---\n");
	printf("please enter n : ");
	scanf("%lf", &n);
	//printf("%lf", n);
	printf("please enter p(x) ");
	scanf("%lf", &p);
	//printf("%lf", p);
	double PMF[(int)n+1];
	double CDF[(int)n+1];
	for(double i = 0.0; i<=n; i++){
		PMF[(int)i] = PMFCount(i, n, p);
		if(i!=0)
			CDF[(int)i] += CDF[(int)i-1]+PMF[(int)i];
		else
			CDF[(int)i] = PMF[(int)i];
		printf("x = %lf, Px(x) = %lf, Fx(X) = %lf\n", i, PMF[(int)i], CDF[(int)i]);
	}
	
	
}
double factorial(double a){
	double key = 1.0;
	for(double i = 1.0; i<=a; i++)
		key *= i;
	return key;
}
double combination(double n, double x){
	return factorial(n)/(factorial(x)*(double)factorial(n-x));
}

double PMFCount(double x, double n, double p){
	return(combination(n, x)*pow(p, x)*pow(1.0-p, n-x));
}

