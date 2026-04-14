#include <math.h>

int FindDistance (struct Point pointA, struct Point pointB)
{
	float distance;
	distance = sqrt( power(pointA.x - pointB.x, 2) - power(pointA.y - pontB.y, 2) );
	return distance;
}