#include<stdio.h>
#include<time.h>
int main(void)
{
	struct tm *ptime;
	time_t lt;
	lt =time(NULL);
	ptime =localtime(&lt);
	printf("second:%d\n",ptime->tm_sec);
	printf("minute:%d\n",ptime->tm_min);
	printf("hour:%d\n",ptime->tm_hour);
	printf("mday:%d\n",ptime->tm_mday);
	printf("month:%d\n",ptime->tm_mon+1);
	printf("year:%d\n",ptime->tm_year+1900);
	printf("weekday:%d\n",ptime->tm_wday);
	printf("yday:%d\n",ptime->tm_yday);
	printf("isdst:%d\n",ptime->tm_isdst);
	printf("gmtoff:%ld\n",ptime->tm_gmtoff);
	printf("zone:%s\n",ptime->tm_zone);
	return 0;
}
