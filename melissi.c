#include <stdio.h>
#include "fileman.h"

#define FLOWER_NAME 32
#define FLOWER_TYPES 8
#define BEHIVES 8
#define REGIONS 16
#define REGION_NAME 32

struct Point
{
	int x;
	int y;
};

struct Flower
{
	char name[FLOWER_NAME];
	int amount;
	int pollen;
	int nectar;
};

struct Region
{
	char name[REGION_NAME];
	struct Point coordinates;
	int temperature;
	int humidity;
	struct Flower flowers[FLOWER_TYPES];
};

struct Beehive
{
	int queenBees;
	int workerBees;
	int beesInside;
	int pollen;
	int nectar;
	int honey;
	int temperature;
	int humidity;
};

struct Apiery
{
	struct Point coordinates;
	struct Beehive beehives[BEHIVES];
};

struct Time
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int main ()
{
	printf("Hello Melissi!");
	FILE *file = fopen("melissi.c", "r");
	PrintFile(file);
	return 0;
}