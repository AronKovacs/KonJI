/*
 * 
 * thank you stack overflow
 */
#include "utilities.h"

#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <windows.h>

long long int getCurrentTime(){
	SYSTEMTIME s;
	FILETIME f;
	LARGE_INTEGER t;

	s.wYear = 1970;
	s.wMonth = 1;
	s.wDay = 1;
	s.wHour = 0;
	s.wMinute = 0;
	s.wSecond = 0;
	s.wMilliseconds = 0;
	SystemTimeToFileTime(&s, &f);
	t.QuadPart = f.dwHighDateTime;
	t.QuadPart <<= 32;
	t.QuadPart |= f.dwLowDateTime;

	return (long long int)t.QuadPart;
}

double getCurrentTimed(){
	return getCurrentTime() / 1000;
}