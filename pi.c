#include <stdio.h>

int main() {
	const int num_steps = 1000;
	double step = 1.0 / num_steps;
	double sum = 0;

	int i;
	for (i = 0; i < num_steps; ++i) {
		double x = (i + 0.5) * step;
		sum += 4 / (1 + (x * x));
	}
	double area = step * sum;

	printf("PI with %d steps is %lf\n", num_steps, area);

	return 0;
}
