#include "Rules.h"

int Rules::getDeployCount(int t_amount, float t_distance)
{
	// Amount
	float a_Tiny = Fuzzy::triangle((float)t_amount, -10, 0, 10);
	float a_Small = Fuzzy::trapezoid((float)t_amount, 2.5f, 10, 15, 20);
	float a_Moderate = Fuzzy::trapezoid((float)t_amount, 15, 20, 25, 30);
	float a_Large = Fuzzy::grade((float)t_amount, 25, 30);

	// Distance
	float d_Close = Fuzzy::triangle(25, -30, 0, 30);
	float d_Medium = Fuzzy::trapezoid(25, 10, 30, 50, 70);
	float d_Far = Fuzzy::grade(25, 50, 70);

	// Threat
	float t_Low = Fuzzy::OR(Fuzzy::OR(
							Fuzzy::AND(d_Medium, a_Tiny),
							Fuzzy::AND(d_Medium, a_Small)), 
							Fuzzy::AND(d_Far, Fuzzy::NOT(a_Large)));

	float t_Medium = Fuzzy::OR(Fuzzy::OR(
							Fuzzy::AND(d_Close, a_Tiny),
							Fuzzy::AND(d_Medium, a_Moderate)),
							Fuzzy::AND(d_Far, a_Large));

	float t_High = Fuzzy::OR(
							Fuzzy::AND(d_Close, Fuzzy::NOT(a_Tiny)),
							Fuzzy::AND(d_Medium, a_Large));

	// Deploy Count
	float deployCount = (t_Low * 10 + t_Medium * 30 + t_High * 50) / 
						(t_Low + t_Medium + t_High);

	return deployCount;
}