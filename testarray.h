//testarray.h
#ifndef __TEST_ARRAY_H__
#define __TEST_ARRAY_H__

#define A_SHORT_LEN 8
int a_short[A_SHORT_LEN] = {-3, 8, -1, 10, -5, -1, 2, 25};

#define A_LONG_LEN 16
int a_long[A_LONG_LEN] = {17, 33, 0, -100, -1, -9, 22, 231, \
                          -3, 8, -1, 10, -5, -1, 2, 25};

#define PATTERNLEN 9
char *patternString1 = "aasdabasd";
char *patternString2 = "asdfbasda";
char *patternString3 = "aasdfbaad";
char *patternString4 = "sdfbasdba";
char *patternString5 = "sdaaasaaa";
char *patternString6 = "abcdfabcd";
char *patternString7 = "abcabcabc";
char *patternString8 = "abcabdabc";
char *patternString9 = "abcabcdab";

#endif