#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265358979323846
using namespace std;

void header()
{
	ofstream fout;
	fout.open("Sphere.txt", ios::out);

	fout
		<< "# vtk DataFile Version 2.0" << endl
		<< "Sphere" << endl
		<< "ASCII" << endl
		<< "DATASET POLYDATA" << endl;

	fout.close();

}

void pointsOnSphere(int NLat, int NMer)
{
	ofstream fout;
	fout.open("Sphere.vtk", ios::app);

	double fiStep = PI / (NLat + 1);
	double thetaStep = (2 * PI) / (NMer);


	fout << "POINTS " << NLat * NMer + 2 << " float" << endl;
	cout << "POINTS " << NLat * NMer + 2 << " float" << endl;


	fout << std::setprecision(3) << std::fixed;
	cout << std::setprecision(3) << std::fixed;


	fout << 0. << " " << 0. << " " << 1. << endl;
	cout << 0. << " " << 0. << " " << 1. << endl;

	for (int i = 1; i <= NLat; i++)
	{
		for (int j = 0; j < NMer; j++)
		{
			fout
				<< sin(i * fiStep) * cos(j * thetaStep) << " "
				<< sin(i * fiStep) * sin(j * thetaStep) << " "
				<< cos(i * fiStep) << endl;
			cout
				<< sin(i * fiStep) * cos(j * thetaStep) << " "
				<< sin(i * fiStep) * sin(j * thetaStep) << " "
				<< cos(i * fiStep) << endl;
		}
	}

	fout << 0. << " " << 0. << " " << -1. << endl;
	cout << 0. << " " << 0. << " " << -1. << endl;



	fout.close();
}

void polygOnSphere(int NLat, int NMer) {
	ofstream fout;
	fout.open("Sphere.vtk", ios::app);

	int np = NLat * NMer + 2;

	fout << "POLYGONS " << 2 * NMer * NLat <<
		" " << 8 * NMer * NLat << endl;
	cout << "POLYGONS " << 2 * NMer * NLat <<
		" " << 8 * NMer * NLat << endl;

	fout << std::setprecision(2) << std::fixed;
	cout << std::setprecision(2) << std::fixed;


	for (int m = 0; m < NLat - 1; m++)
	{
		for (int n = 0; n < NMer; n++)
		{
			fout
				<< 3 << " "
				<< n + m * NMer + 1 << " "
				<< ((n + 1) % NMer) + m * NMer + 1 << " "
				<< ((n + 1) % NMer) + NMer + m * NMer + 1 << endl;
			fout
				<< 3 << " "
				<< ((n + 1) % NMer) + NMer + m * NMer + 1 << " "
				<< n + NMer + m * NMer + 1 << " "
				<< n + m * NMer + 1 << endl;
			cout
				<< 3 << " "
				<< n + m * NMer + 1 << " "
				<< ((n + 1) % NMer) + m * NMer + 1 << " "
				<< ((n + 1) % NMer) + NMer + m * NMer + 1 << endl;
			cout
				<< 3 << " "
				<< ((n + 1) % NMer) + NMer + m * NMer + 1 << " "
				<< n + NMer + m * NMer + 1 << " "
				<< n + m * NMer + 1 << endl;

		}
	}

	for (int i = 0; i < NMer; i++) {
		fout
			<< 3 << " "
			<< np-1 << " "
			<< np - 2 - i << " "
			<< np - 2 - ((i + 1) % NMer) << endl;

		fout
			<< 3 << " "
			<< 0 << " "
			<< i + 1 << " "
			<< (i + 1) % NMer + 1 << endl;
		cout
			<< 3 << " "
			<< np - 1 << " "
			<< np - 2 - i << " "
			<< np - 2 - ((i + 1) % NMer) << endl;

		cout
			<< 3 << " "
			<< 0 << " "
			<< i + 1 << " "
			<< (i + 1) % NMer + 1 << endl;
	}

	fout.close();
}

void Sphere(int NLat, int NMer) {
	header();
	pointsOnSphere(NLat, NMer);
	polygOnSphere(NLat, NMer);
}

int main()
{
	Sphere(4, 4);
}