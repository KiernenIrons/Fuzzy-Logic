#include "Fuzzy.h"

float Fuzzy::grade(float t_value, float t_x0, float t_x1)
{
    if (t_value <= t_x0)
    {
        return 0.0f;
    }
    else if (t_value > t_x1)
    {
        return 1.0f;
    }
    else
    {
        return (t_value - t_x0) / (t_x1 - t_x0);
    }
}

float Fuzzy::trapezoid(float t_value, float t_x0, float t_x1, float t_x2, float t_x3)
{
    if (t_value <= t_x0 or t_value >= t_x3)
    {
        return 0.0f;
    }
    else if (t_value >= t_x1 and t_value <= t_x2)
    {
        return 1.0f;
    }
    else if (t_value >= t_x0 and t_value <= t_x1)
    {
        return (t_value - t_x0) / (t_x1 - t_x0);
    }
    else
    {
        return (t_x3 - t_value) / (t_x3 - t_x2);
    }
}

float Fuzzy::triangle(float t_value, float t_x0, float t_x1, float t_x2)
{
    if (t_value <= t_x0 or t_value >= t_x2)
    {
        return 0.0f;
    }
    else if (t_value == t_x1)
    {
        return 1.0f;
    }
    else if (t_value > t_x0 and t_value < t_x1)
    {
        return (t_value - t_x0) / (t_x1 - t_x0);
    }
    else
    {
        return (t_x2 - t_value) / (t_x2 - t_x1);
    }
}

float Fuzzy::AND(float t_A, float t_B)
{
	return std::min(t_A, t_B);
}

float Fuzzy::OR(float t_A, float t_B)
{
	return std::max(t_A, t_B);
}

float Fuzzy::NOT(float t_A)
{
	return 1.0f - t_A;
}
