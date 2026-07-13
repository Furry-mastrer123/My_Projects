#include "ROUND.h"
double func1(double  x,double y)
{
#ifdef ROUND
	return ROUND(x + y);
#else
	return x+y;
#endif // ROUND
}
#undef ROUND
double func2(double x,double y)
{
#ifdef ROUND
	return ROUND(x + y);
#else
	return x+y;
#endif // ROUND
}