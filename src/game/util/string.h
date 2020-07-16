#ifndef STRING_H
#define STRING_H

#include "general.h"

typedef struct {
  char *str;
  u32 len; // <= cap
  u32 cap;
} String;

inline String newString(u32 capacity = 0) {
  return String{(char *)malloc(capacity * sizeof(char)), capacity, capacity};
}

inline void allocString(String *str, u32 len) {
  if (len <= str->cap)
    return;
  str->cap <<= 1;

  char *const oldStrHead = str->str;
  str->str = (char *)malloc(str->cap * sizeof(char));

  char *newStr = str->str;
  char *oldStr = oldStrHead;
  while (*oldStr != 0) {
    *newStr = *oldStr;
    newStr += 1;
    oldStr += 1;
  }

  free(oldStrHead);
}

inline void pushChar(String *str, char c) {
  allocString(str, str->len + 1);
  str->len += 1;

  str->str[str->len - 1] = c;
  str->str[str->len] = '\0';
}

inline void pushStr(String *str, String const *toPush) {
  allocString(str, str->len + toPush->len);

  u32 const len = str->len + toPush->len - 1;
  FOR_INCR(u32, idx, toPush->len) {
    str->str[idx + str->len - 1] = toPush->str[idx];
  }
  str->len = len;
}

BOOL equalsStr(String const *l, String const *r) {
  if (l->len != r->len) {
    return NO;
  }
  FOR_INCR(u32, idx, l->len) {
    if (l->str[idx] != r->str[idx]) {
      return NO;
    }
  }
  return YES;
}

inline String fromRaw(char const *raw) {
  char const *tail = raw;
  while (*tail != 0) {
    tail += 1;
  }

  u32 length = tail - raw + 1;
  char *buf = (char *)malloc(length * sizeof(char));
  FOR_INCR(u32, idx, length) { buf[idx] = raw[idx]; }

  return String{buf, length, length};
}

inline char const *asCstr(String *str) { return str->str; }

#endif // STRING_H
