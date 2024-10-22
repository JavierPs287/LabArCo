#include <stdio.h>
#include <omp.h>

void main()
{
omp_set_num_threads(4);
#pragma omp parallel
{
printf("Hello world by thread: %d\n", omp_get_thread_num());
}
}