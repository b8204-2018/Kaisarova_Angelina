#include "pch.h"
#include "Darts.h"
#include <iostream>


int Darts ( float x, float y)
{
	float r;
	int kol;
	if (x <= 4 && x >= 0 && y <= 4 && y >= 0) {
		r = sqrt(pow(x, 2) + pow(y, 2));
		if (r <= 1) {
			kol = 5;
		}
		else if (r <= 2)
		{
			kol = 4;
		}
		else if (r <= 3)
		{
			kol = 3;
		}
		else if (r <= 4)
		{
			kol = 2;
		}
		else
		{
			kol = 1;
		}
		printf( "%s%d", "Kolichestvo = ", kol);
	}
	else {
		printf( "%s", "Incorrectly");
	}
	return 0;
}
