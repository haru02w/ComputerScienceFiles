#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double core(int option);

int main(int argc, char *argv[])
{
	int lines, option;
	scanf("%d", &lines);
	for (int i = 0; i < lines; i++) {
		scanf("%d", &option);
		printf("%.2lf\n", core(option));
	}
	return 0;
}

double core(int option)
{
	double result, aceleration, velocity, space, time;
	switch (option) {
	case 1:
		scanf("%lf %lf", &velocity, &time);
		result = velocity * time;
		break;
	case 2:
		scanf("%lf %lf", &space, &time);
		result = space / time;
		break;
	case 3:
		scanf("%lf %lf", &space, &velocity);
		result = space / velocity;
		break;
	case 4:
		scanf("%lf %lf %lf", &velocity, &aceleration, &time);
		result = (velocity * time) + (aceleration * time * time) / 2;
		break;
	case 5:
		scanf("%lf %lf %lf", &velocity, &aceleration, &time);
		result = velocity + (aceleration * time);
		break;
	case 6:
		scanf("%lf %lf %lf", &space, &aceleration, &time);
		result = (space - (aceleration * time * time) / 2) / time;
		break;
	case 7:
		scanf("%lf %lf %lf", &space, &velocity, &aceleration);
		result = (sqrt((velocity * velocity) +
			       (2 * aceleration * space)) -
			  velocity) /
			 aceleration;
		break;
	}
	return result;
}
