
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void addArrays(int *a, int *b, int *c)
{
	int idx = threadIdx.x;
	c[idx] = a[idx] + b[idx];
}

int main()
{
	int ha[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int hb[] = { 5, 3, 2, 3, 1, 2, 6, 7, 8, 50 };
	int hc[10];

	int *da, *db, *dc;

	int size = sizeof(int)*10;

	cudaMalloc((void**)&da, size);
	cudaMalloc((void**)&db, size);
	cudaMalloc((void**)&dc, size);

	cudaMemcpy(da, ha, size, cudaMemcpyKind::cudaMemcpyHostToDevice);
	cudaMemcpy(db, hb, size, cudaMemcpyKind::cudaMemcpyHostToDevice);

	addArrays <<<1, 10 >>>(da, db, dc);	
	

	cudaMemcpy(hc, dc, size, cudaMemcpyKind::cudaMemcpyDeviceToHost);

	for (int i = 0; i < 10; i++)
		printf("%d\n", hc[i]);

	return 0;
}