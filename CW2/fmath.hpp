#pragma once
#include <cmath>
#include <algorithm>

const static float DELTA_FLOAT = 0.001f;

class fmath
{
	public:
	
		static float randFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		static bool sameFloat(float a, float b)
		{
			float aAbs = std::fabs(a);
			float bAbs = std::fabs(b);

			return (std::fabs(aAbs - bAbs) < DELTA_FLOAT);
		}

		static float clip(float n, float lower, float upper)
		{
			return std::max(lower, std::min(n, upper));
		}
};