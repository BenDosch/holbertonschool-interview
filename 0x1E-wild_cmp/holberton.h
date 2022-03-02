#ifndef Holberton_H
#define Holberton_H

#include <stddef.h>

int wildcmp(char *s1, char *s2);
int test(char *s1, char *s2, int wild);
size_t wild_count(char *s2, size_t count);
char * shift_2(char *s2);
char * shift_1(char *s1, char *s2);

#endif
