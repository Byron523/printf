#ifndef MAIN_H
#define MAIN_H

#ifndef reverse_string
#undef reverse_string
#endif

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} argument_types;

int _putchar(char *buf, unsigned int nbuf);
int _printf(const char *format, ...);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
int (*fpntr_func(const char *s, int index))(va_list, char *, unsigned int);
int number_of_ident(const char *s, int n);
int print_c(va_list a __attribute__((unused)), char *buf, unsigned int i);
int print_char(va_list arguments, char *buf, unsigned int ibuf);
int _hex(va_list ptr, char *buf, unsigned int ibuf);
int _octal(va_list ptr, char *buf, unsigned int ibuf);
int long_dec_hex(va_list ptr, char *buf, unsigned int ibuf);
int print_long_int(va_list ptr, char *buf, unsigned int ibuf);
int _long_oct(va_list ptr, char *buf, unsigned int ibuf);
int _unsigned_int(va_list ptr, char *buf, unsigned int ibuf);
int _long_int(va_list ptr, char *buf, unsigned int ibuf);
char *_binary_array(char *binary, long int int_in, int isneg, int limit);
char *_hex_array(char *bnr, char *hex, int isupp, int limit);
char *_long_oct_array(char *bnr, char *oct);
char *_short_oct_array(char *bnr, char *oct);
int _binary(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int prinpint(va_list arguments, char *buf, unsigned int ibuf);
int reverse_string(va_list arguments, char *buf, unsigned int ibuf);
int rot13_cipher(va_list arguments, char *buf, unsigned int ibuf);
int _address(va_list arguments, char *buf, unsigned int ibuf);
int prinhhex(va_list arguments, char *buf, unsigned int ibuf);
int prinhint(va_list arguments, char *buf, unsigned int ibuf);
int prinhoct(va_list arguments, char *buf, unsigned int ibuf);
int prinhunt(va_list arguments, char *buf, unsigned int ibuf);
int prinhupx(va_list arguments, char *buf, unsigned int ibuf);
int prinsint(va_list arguments, char *buf, unsigned int ibuf);
int print_string(va_list arguments, char *buf, unsigned int ibuf);
int print_unsigned_int(va_list arguments, char *buf, unsigned int ibuf);
int print_decimal_hex(va_list arguments, char *buf, unsigned int ibuf);
int string_values(va_list arguments, char *buf, unsigned int ibuf);
int prinpint(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);

#endif
