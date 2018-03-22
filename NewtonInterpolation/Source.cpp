#include <iostream>

using namespace std;

double newtonInterpolation(double *x, double *y, double xarg, int size)
{
	double *yy=new double[size];
	for (int i = 0; i < size; i++) yy[i] = y[i];
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--) yy[j] = (yy[j] - yy[j - 1]) / (x[j] - x[j - i - 1]);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		double mult = 1;
		for (int j = 0; j < i; j++) mult *= (xarg - x[j]);
		mult *= yy[i];
		result += mult;
	}
	delete[] yy;
	return result;
}

int main()
{
	double x[] = { 80,90,100,110,120 };
	double y[] = { 25,30,42,50,68 };
	
	int n = 5;

	cout << newtonInterpolation(x, y, 85, n) << endl;
	cout << newtonInterpolation(x, y, 55, n) << endl;
	cout << newtonInterpolation(x, y, 65, n) << endl;
	cout << newtonInterpolation(x, y, 75, n) << endl;
	
	system("pause");
	return 0;
}