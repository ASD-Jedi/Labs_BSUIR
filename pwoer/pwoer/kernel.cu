#include <stdio.h>
#include <time.h>

__global__ void bubbleMove(int *array_device, int N, int step){
	int idx = blockDim.x * blockIdx.x + threadIdx.x;
	if (idx<(N - 1)) {
		if (step - 2 >= idx){
			if (array_device[idx]<array_device[idx + 1]){
				int buffer = array_device[idx];
				array_device[idx] = array_device[idx + 1];
				array_device[idx + 1] = buffer;
			}
		}
	}
}

void bubleSortCUDA(int *array_host, int N, int blockSize){
	int *array_device; cudaMalloc((void **)&array_device, N * sizeof(int));
	for (int i = 0; i < N; i++) array_host[i] = i;
	cudaMemcpy(array_device, array_host, N*sizeof(int), cudaMemcpyHostToDevice);
	int nblocks = N / blockSize + 1;
	for (int step = 0; step <= N + N; step++) {
		bubbleMove << <nblocks, blockSize >> >(array_device, N, step);
		cudaThreadSynchronize();
	}
	cudaMemcpy(array_host, array_device, N*sizeof(int), cudaMemcpyDeviceToHost);
	cudaFree(array_device);
}

void bubleSortCPU(int *array_host, int N){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N - i - 1; j++) {
			if (array_host[j]<array_host[j + 1]){
				int buffer = array_host[j];
				array_host[j] = array_host[j + 1];
				array_host[j + 1] = buffer;
			}
		}
	}
}

int checkArray(int *array_host, int N){
	int good = 1;
	for (int i = 0; i < N - 1; i++) if (array_host[i]<array_host[i + 1]) { good = 0; printf("i=%d a=%d\n", i, array_host[i]); }
	return good;
}

float measureCUDA(int N, int blockSize){
	int *array_host = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) array_host[i] = i;
	clock_t start = clock();
	bubleSortCUDA(array_host, N, blockSize);
	clock_t end = clock();
	if (checkArray(array_host, N) == 1){
		free(array_host);
		return (float)(end - start) / CLOCKS_PER_SEC;
	}
	else {
		free(array_host);
		return -1;
	}
}

float measureCPU(int N) {
	int *array_host = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) array_host[i] = i;
	clock_t start = clock();
	bubleSortCPU(array_host, N);
	clock_t end = clock();
	if (checkArray(array_host, N) == 1){
		free(array_host);
		return (float)(end - start) / CLOCKS_PER_SEC;
	}
	else {
		free(array_host);
		return -1;
	}
}

int main(int argc, char const *argv[]) {
	for (int i = 1; i < 10000000; i *= 2) printf("%d %f\t%f\n", i, measureCUDA(i, 256), measureCPU(i));
	return 0;
}
