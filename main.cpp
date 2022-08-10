#include <iostream>
#include <cmath>
#include <fstream>


double ExpSeries(double x, int N)
{
	// approximates exp(x) by Maclaurin series using a recurrance relation
	// reccurance relation : T_n = x/n * T_n-1
	// defining first term
	double a = 1; 
	// Sums N+1 terms as first term is always included here
	double sum = a; 
	for (int i = 1; i <= N; i++) //sums N terms
	{
		// calculates next term using reccurance relation
		double b = (x / i) * a; 
		sum += b; 
		a = b;
	}
	return sum;
}



int main()
{
	// declare object of type std::ofstream
	std::ofstream File;

	// try opening file
	File.open("Data.txt");

	// if file failed to open, exit main returning 1
	if (!File) return 1;

	// writing to the file
	for (double z = -1.0; z < 1.02; z+=0.02)
	{
		File.width(10); File << z;
		File.width(10); File << exp(z);
		File.width(10); File << ExpSeries(z, 1);
		File.width(10); File << ExpSeries(z, 2);
		File.width(10); File << ExpSeries(z, 3) << std::endl;
	}

	// close the file
	File.close();

	return 0;
}