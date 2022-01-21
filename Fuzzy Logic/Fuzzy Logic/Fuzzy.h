#ifndef FUZZY_HPP
#define FUZZY_HPP

#include <iostream>
#include <algorithm>

namespace Fuzzy
{
	float grade(float t_value, float t_x0, float t_x1);
	float trapezoid(float t_value, float t_x0, float t_x1, float t_x2, float t_x3);
	float triangle(float t_value, float t_x0, float t_x1, float t_x2);

	float AND(float t_A, float t_B);
	float OR(float t_A, float t_B);
	float NOT(float t_A);
};
#endif