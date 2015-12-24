/*
 * 
 * thank you stack overflow
 */
#include "utilities.h"

#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <windows.h>

unsigned long long int getCurrentTime(){
	SYSTEMTIME s;
	FILETIME f;

	GetSystemTime(&s);
	SystemTimeToFileTime(&s, &f);

	unsigned long long int result = (((ULONGLONG)f.dwHighDateTime) << 32) + f.dwLowDateTime;

	return result;
}

double getCurrentTimed(){
	return (double)getCurrentTime() / 10000.0;
}