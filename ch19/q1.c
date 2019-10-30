#include <stdio.h>
#include <sys/time.h>

int main(int argc, char const *argv[])
{
	struct timeval *tv;
	struct timezone *tz;
	printf("rc = %d\n",gettimeofday(tv, tz) );
	printf("Seconds = %ld\n",tv->tv_sec);
	printf("Microseconds = %ld\n",tv->tv_usec);
	return 0;
}