#include <stdio.h>
#include <omp.h>

void main() {
	const int num_steps = 1000;
	double step = 1.0 / num_steps;
	double area = 0;

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int nthreads = omp_get_num_threads();
		double sum = 0;

		int i;
		for (i = id; i < num_steps; i += nthreads) {
			double x = (i + 0.5) * step;
			sum += 4 / (1 + (x * x));
		}

		#pragma omp critical
		{
			area += sum * step;
		}
	}

	printf("PI with %d steps is %lf\n", num_steps, area);
}
