#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N = 1000000000; // iterating for a billion times
	double pi = 0; // variable to store the value of computed pi
	double delta_x = (double)1/N; // delta_x defined to be 1/N
	for(int i=0;i<N;i++)
	{
		pi += delta_x*sqrt(1-(i*delta_x)*(i*delta_x));
	}
	cout<<(double)4*pi<<endl; // multiplying by 4 as the value computed in pi is 1/4th of the constant pi
	return 0;
}
