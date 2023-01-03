#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  size_t i;
  unsigned char *tmp_s;
  unsigned char tmp_chr;

  if (str == s21_NULL)
    return (s21_NULL);

  tmp_s = (unsigned char *)str;
  tmp_chr = (unsigned char)c;
  i = 0;
  while (i < n) {
    if (*tmp_s == tmp_chr)
      return (tmp_s);
    i++;
    tmp_s++;
  }
  return (s21_NULL);
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  size_t i;
  size_t j;
  unsigned char *tmp_s1;
  unsigned char *tmp_s2;

  if (str1 == s21_NULL && str2 == s21_NULL)
    return (0);
  tmp_s1 = (unsigned char *)str1;
  tmp_s2 = (unsigned char *)str2;

  i = 0;
  j = 0;
  while (i < n) {
    if (tmp_s1[i] != tmp_s2[j])
      return (tmp_s1[i] - tmp_s2[j]);
    i++;
    j++;
  }
  return (0);
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  size_t i;
  unsigned char *tmp_dest;
  unsigned char *tmp_src;

  if (src == s21_NULL)
    return (s21_NULL);

  tmp_dest = (unsigned char *)dest;
  tmp_src = (unsigned char *)src;

  i = 0;
  while (i < n) {
    *tmp_dest++ = *tmp_src++;
    i++;
  }
  return (dest);
}

void *s21_memset(void *str, int c, size_t n) {
  size_t i;
  unsigned char *tmp_s;

  if (str == s21_NULL)
    return (s21_NULL);

  tmp_s = (unsigned char *)str;
  i = 0;
  while (i < n) {
    *tmp_s++ = c;
    i++;
  }
  return (str);
}

char *s21_strcat(char *dest, const char *src) {
  int i;
  int j;
  unsigned char *tmp_dest;
  unsigned char *tmp_src;

  tmp_dest = (unsigned char *)dest;
  tmp_src = (unsigned char *)src;
  i = 0;
  while (tmp_dest[i] != '\0') {
    i++;
  }
  j = 0;
  while (tmp_src[j] != '\0') {
    tmp_dest[i] = tmp_src[j];
    i++;
    j++;
  }
  tmp_dest[i] = '\0';
  return (dest);
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  int i;
  size_t j;
  unsigned char *tmp_dest;
  unsigned char *tmp_src;
  if (src == s21_NULL)
    return (s21_NULL);
  tmp_dest = (unsigned char *)dest;
  tmp_src = (unsigned char *)src;
  i = 0;
  while (tmp_dest[i] != '\0') {
    i++;
  }
  j = 0;
  while (tmp_src[j] != '\0' && j < n) {
    tmp_dest[i] = tmp_src[j];
    i++;
    j++;
  }
  tmp_dest[i] = '\0';
  return (dest);
}

char *s21_strchr(char *str, int c) {
  if (str == s21_NULL)
    return (s21_NULL);

  while (*str != '\0') {
    if (*str == c)
      return str;
    str++;
  }
  if (c == '\0')
    return str;
  return (s21_NULL);
}

int s21_strcmp(char *str1, char *str2) {
  int ret = 0;

  while (*str1 && *str2) {
    if (*str1 != *str2) {
      ret = *str1 - *str2;
      break;
    }
    ++str1;
    ++str2;
  }
  if (!ret) {
    ret = *str1 ? *str1 : *str2 ? -(*str2) : 0;
  }
  return ret;
}

char *s21_strcpy(char *dest, const char *src) {
  int i;
  unsigned char *tmp_dest;
  unsigned char *tmp_src;
  if (dest == s21_NULL || src == s21_NULL)
    return (s21_NULL);
  tmp_dest = (unsigned char *)dest;
  tmp_src = (unsigned char *)src;
  i = 0;
  while (tmp_src[i] != '\0') {
    tmp_dest[i] = tmp_src[i];
    i++;
  }
  tmp_dest[i] = '\0';
  return (dest);
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  size_t i;
  unsigned char *tmp_dest;
  unsigned char *tmp_src;

  if (n == 0)
    return (dest);
  if (dest == s21_NULL || src == s21_NULL)
    return (s21_NULL);
  tmp_dest = (unsigned char *)dest;
  tmp_src = (unsigned char *)src;
  i = 0;
  while (i < n && tmp_src[i] != '\0') {
    tmp_dest[i] = tmp_src[i];
    i++;
  }
  if (tmp_src[i] != '\0')
    tmp_dest[i] = '\0';
  return (dest);
}

int s21_strcspn(const char *str1, const char *str2) {
  int ans = 0;
  int found = 0;
  for (; *(str1); str1++) {
    for (int i = 0; *(str2 + i); i++) {
      if (*(str1) == *(str2 + i)) {
        found = 1;
        break;
      }
    }
    if (found) {
      break;
    }
    ans++;
  }
  return ans;
}

int s21_strlen(const char *str) {
  size_t i;
  unsigned char *tmp_s;

  tmp_s = (unsigned char *)str;
  i = 0;
  while (tmp_s[i] != '\0') {
    i++;
  }
  return (i);
}

char *s21_strpbrk(char *str1, char *str2) {
  if (str1 == s21_NULL || s21_strlen(str2) == 0)
    return (s21_NULL);

  while (*str1 != '\0') {
    if (s21_strchr(str2, *str1) != s21_NULL) {
      return (str1);
    }
    str1++;
  }
  return (s21_NULL);
}

int s21_strspn(const char *str1, const char *str2) {
  size_t count;
  unsigned char *tmp_str1;
  unsigned char *tmp_str2;

  tmp_str1 = (unsigned char *)str1;
  tmp_str2 = (unsigned char *)str2;

  count = 0;
  while (*tmp_str2 == *tmp_str1) {
    count++;
    tmp_str2++;
    tmp_str1++;
  }
  if (count > 0)
    return (count);
  return (0);
}

char *s21_strstr(char *haystack, char *needle) {
  unsigned int i;
  unsigned int j;

  if (haystack == s21_NULL)
    return (s21_NULL);

  if (*needle == '\0')
    return (haystack);

  i = 0;
  while (haystack[i] != '\0') {
    j = 0;
    while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
      if (needle[j + 1] == '\0')
        return (haystack + i);
      j++;
    }
    i++;
  }
  return (0);
}

char *s21_strtok(char *str, char *delim) {
  char *tmp_ptr;
  static char *token = s21_NULL;

  if (delim == s21_NULL)
    return (s21_NULL);

  if (str == s21_NULL) {
    if (token == s21_NULL)
      return (s21_NULL);
    str = token;
  }
  if (*str == 0 && *delim != 0)
    return (s21_NULL);
  while (s21_strchr(delim, *str) != s21_NULL)
    str++;
  tmp_ptr = str;
  while (*str != '\0') {
    if (s21_strchr(delim, *str) != s21_NULL)
      break;
    str++;
  }
  if (*str == '\0') {
    token = s21_NULL;
    return (tmp_ptr);
  }
  *str = 0;
  token = str + 1;
  return (tmp_ptr);
}

char *s21_strjoin(char *s1, char *s2) {
  int i = 0;
  char *out;
  int size;

  if (s1 == s21_NULL || s2 == s21_NULL)
    return (NULL);
  size = s21_strlen(s1) + s21_strlen(s2);
  out = malloc(size + 1);
  if (out == s21_NULL)
    return (s21_NULL);
  while (*s1)
    out[i++] = *s1++;
  while (*s2)
    out[i++] = *s2++;
  out[i] = 0;
  return (out);
}

char *s21_strdup(char *s1) {
  size_t len;
  char *str;
  char *tmp;

  len = s21_strlen(s1);
  str = malloc(len + 1);
  if (str == NULL)
    return (NULL);
  tmp = str;
  while (*s1 != '\0') {
    *str++ = *s1++;
  }
  *str = '\0';
  return (tmp);
}
