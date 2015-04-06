
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

__global__ void arraySort(int *a)
{
	int idx = threadIdx.x;
	if (a[idx + 1] > a[idx])
	{
		int buffer = a[idx];
		a[idx] = a[idx + 1];
		a[idx + 1] = buffer;
	}
}

int main()
{
	int ha[100000], hv[100000];
	
	int size = sizeof(int) * 100000;
	
	srand(time(0));

	for (int i = 0; i < 100000; i++)
		ha[i] = rand() % 187459356 + 134;

	int *dm;

	cudaMalloc((void**) & dm, size);

	cudaMemcpy(dm, ha, size, cudaMemcpyKind::cudaMemcpyHostToDevice);

	arraySort << <20, 100000 >> >(dm);

	cudaMemcpy(dm, hv, size, cudaMemcpyKind::cudaMemcpyDeviceToHost);

	for (int i = 0; i < 100000; i++)
		printf("%d\t", hv[i]);

	getchar();
	return 0;

}