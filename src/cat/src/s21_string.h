#ifndef S21_STRING_H_
#define S21_STRING_H_

#define s21_NULL (void *)0

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(char *str, int c);
int s21_strcmp(char *str1, char *str2);
int s21_strncmp(const char *str1, const char *str2, int n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
int s21_strcspn(const char *str1, const char *str2);
int s21_strlen(const char *str);
char *s21_strpbrk(char *str1, char *str2);
char *s21_strrchr(const char *str, int c);
int s21_strspn(const char *str1, const char *str2);
char *s21_strstr(char *haystack, char *needle);
char *s21_strtok(char *str, char *delim);
char *s21_strjoin(char *s1, char *s2);
char *s21_strdup(char *s1);

#endif // S21_STRING_H_