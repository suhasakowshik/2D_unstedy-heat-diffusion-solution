/*
The program solves 2D unsteady heat conduction equation. It uses Forward time and Central Space differencing i e., FTCS method.
FDM solution.
x and y are grid length of 1 units.

d= (alpha * deltat)/(delta^2) ;
alpha = 17.6e-06 for stainless steel.

N is grid length
Nt time length
delta is deltax

output data is for the cases 5 , 20, 50 and 7200 seconds
imort data in matlab, code is given to plot contour (file name plot_data.m)
*/

#include<iostream>
#include<math.h>
#include<fstream>
#include <cstdlib>
using std::ofstream;
using std::endl;
using namespace std;
int main()
{
	double x, y, size, d, time;
	double delta, deltat;
	ofstream outdata;
	int N, Nt,i,j;
	i = 0;
	j = 0;
	x = 1;
	y = 1;
	N = 100;
	Nt =7200;
	time = 7200;
	d = 0.176;


	delta = x / N;
	deltat = time / Nt;
	double T[101][101];

	
	double g;
	double e = 0.0;
	double f = 0.0;

	/*Initial Conditions*/
    for (int i = 0; i <= N; i++)
	{
		f = i * delta;
		
		for (int j = 0; j <= N; j++)
		{
			e = j * delta;
			g = pow((e - 0.5), 2) + pow((f - 0.5), 2);
			if (g < 0.2)
			{
				T[i][j] = 313;
			}
			else
			{
				T[i][j] = 293;
			}

		}

	}
	 /* Boundary Conditions */
	for (int i = 0; i <= N ; i++)
	{
		T[0][i] = 293;
	};
	for (int i = 0; i <= N; i++)
	{
		T[N][i] = 293;
	};
	for (int i = 0; i <= N ; i++)
	{
		T[i][0] = 293;
	};
	for (int i = 0; i <= N; i++)
	{
		T[i][N] = 293;
	};

    /* FDM equation solution*/
	for (int t = 1; t <= time; t = t + deltat)
	{
		for (int i = 1; i <= (N - 1); i = i + 1)
		{
			for (int j = 1; j <= (N - 1); j = j + 1)
			{

				T[i][j] = T[i][j] + d * (T[i + 1][j] + T[i - 1][j] - 4 * T[i][j] + T[i][j + 1] + T[i][j - 1]);
				
			}

			
		}

		/* Writing output file in the format .dat */
		if (t == 5)
		{
			outdata.open("data5.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i][0];
				for (int j = 0; j <= N; j = j + 1)
				{
					outdata << " " << T[i][j];
				}
				outdata << endl;
			}
			outdata.close();
		}
		else if (t == 20)
		{
			outdata.open("data20.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i][0];
				for (int j = 0; j <= N; j = j + 1)
				{
					outdata << " " << T[i][j];
				}
				outdata << endl;
			}
			outdata.close();

		}
		else if (t == 50)
		{
			outdata.open("data50.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i][0];
				for (int j = 0; j <= N; j = j + 1)
				{
					outdata << " " << T[i][j];
				}
				outdata << endl;
			}
			outdata.close();

		}
		else if (t == 7200)
		{
			outdata.open("data7200.dat");
			for (int i = 0; i <= N; i = i + 1)
			{
				outdata << T[i][0];
				for (int j = 0; j <= N; j = j + 1)
				{
					outdata << " " << T[i][j];
				}
				outdata << endl;
			}
			outdata.close();

		}
		
	}

};
