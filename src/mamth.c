#include <math.h>

struct Point
{
	int x;
	int y;
};

float FindDistance (struct Point pointA, struct Point pointB)
{
	float distance;
	distance = sqrt( pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2) );
	return distance;
}
