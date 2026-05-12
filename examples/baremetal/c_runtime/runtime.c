#include "runtime.h"

#include <stdarg.h>

extern void htif_putc(int c);

static int put_char(char c)
{
  int written = 0;

  if (c == '\n') {
    htif_putc('\r');
    ++written;
  }

  htif_putc(c);
  ++written;
  return written;
}

static int put_string(const char *value)
{
  int written = 0;

  if (value == 0) {
    value = "(null)";
  }

  while (*value != '\0') {
    written += put_char(*value);
    ++value;
  }

  return written;
}

static int put_unsigned(unsigned long value, unsigned int base)
{
  char buffer[32];
  unsigned int index = 0;
  int written = 0;

  if (value == 0) {
    return put_char('0');
  }

  while (value != 0) {
    unsigned long digit = value % base;
    buffer[index] = (digit < 10) ? (char)('0' + digit) : (char)('a' + digit - 10);
    value /= base;
    ++index;
  }

  while (index != 0) {
    --index;
    written += put_char(buffer[index]);
  }

  return written;
}

static int put_signed(long value)
{
  if (value < 0) {
    return put_char('-') + put_unsigned((unsigned long)(-value), 10);
  }

  return put_unsigned((unsigned long)value, 10);
}

int printf(const char *format, ...)
{
  int written = 0;
  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    if (*format != '%') {
      put_char(*format);
      ++written;
      ++format;
      continue;
    }

    ++format;

    switch (*format) {
    case '%':
      written += put_char('%');
      break;
    case 'c':
      written += put_char((char)va_arg(args, int));
      break;
    case 'd':
    case 'i':
      written += put_signed((long)va_arg(args, int));
      break;
    case 'u':
      written += put_unsigned((unsigned long)va_arg(args, unsigned int), 10);
      break;
    case 'x':
      written += put_unsigned((unsigned long)va_arg(args, unsigned int), 16);
      break;
    case 's':
      written += put_string(va_arg(args, const char *));
      break;
    default:
      written += put_char('%');
      written += put_char(*format);
      break;
    }

    ++format;
  }

  va_end(args);
  return written;
}
