#include "main.h"
#include <stdio.h>
/**
 * fpntr_func - selects function operators.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*fpntr_func(const char *s, int index))(va_list, char *, unsigned int)
{
	argument_types func_ops[] = {
		{"c", print_char}, {"s", print_string},
		{"i", print_int}, {"d", print_int},
		{"b", _binary}, {"u", print_unsigned_int},
		{"o", _octal}, {"x", _hex},
		{"X", print_decimal_hex}, {"S", string_values},
		{"p", _address}, {"li", _long_int},
		{"ld", _long_int}, {"lu", _unsigned_int},
		{"lo", _long_oct}, {"lx", long_dec_hex},
		{"lX", prinhupx}, {"hi", prinhint},
		{"hd", prinhint}, {"hu", prinhunt},
		{"ho", prinhoct}, {"hx", prinhhex},
		{"hX", prinhupx}, {"#o", prinhoct},
		{"#x", prinhhex}, {"#X", prinhupx},
		{"#i", print_int}, {"#d", print_int},
		{"#u", print_unsigned_int}, {"+i", prinpint},
		{"+d", prinpint}, {"+u", print_unsigned_int},
		{"+o", _octal}, {"+x", _hex},
		{"+X", print_decimal_hex}, {" i", prinsint},
		{" d", prinsint}, {" u", print_unsigned_int},
		{" o", _octal}, {" x", _hex},
		{" X", print_decimal_hex}, {"R", rot13_cipher},
		{"r", reverse_string}, {"%", print_c},
		{"l", print_c}, {"h", print_c},
		{" +i", prinpint}, {" +d", prinpint},
		{"+ i", prinpint}, {"+ d", prinpint},
		{" %", print_c}, {NULL, NULL},
	};
	int i = 0, j = 0, f_index;

	f_index = index;
	while (func_ops[i].type_arg)
	{
		if (s[index] == func_ops[i].type_arg[j])
		{
			if (func_ops[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = f_index;
		}
	}
	return (func_ops[i].f);
}

/**
 * number_of_ident - returns the amount of identifiers.
 * @s: argument indentifier
 * @n: index of argument identifier.
 * Return: amount of identifiers.
 */
int number_of_ident(const char *s, int n)
{
	argument_types func_ops[] = {
		{"c", print_char}, {"s", print_string}, {"i", print_int},
		{"d", print_int}, {"b", _binary}, {"u", print_unsigned_int},
		{"o", _octal}, {"x", _hex}, {"X", print_decimal_hex},
		{"S", string_values}, {"p", _address}, {"li", _long_int},
		{"ld", _long_int}, {"lu", _unsigned_int}, {"lo", _long_oct},
		{"lx", long_dec_hex}, {"lX", prinhupx}, {"hi", prinhint},
		{"hd", prinhint}, {"hu", prinhunt}, {"ho", prinhoct},
		{"hx", prinhhex}, {"hX", prinhupx}, {"#o", prinhoct},
		{"#x", prinhhex}, {"#X", prinhupx}, {"#i", print_int},
		{"#d", print_int}, {"#u", print_unsigned_int}, {"+i", prinpint},
		{"+d", prinpint}, {"+u", print_unsigned_int}, {"+o", _octal},
		{"+x", _hex}, {"+X", print_decimal_hex}, {" i", prinsint},
		{" d", prinsint}, {" u", print_unsigned_int}, {" o", _octal},
		{" x", _hex}, {" X", print_decimal_hex}, {"R", rot13_cipher},
		{"r", reverse_string}, {"%", print_c}, {"l", print_c},
		{"h", print_c}, {" +i", prinpint}, {" +d", prinpint},
		{"+ i", prinpint}, {"+ d", prinpint}, {" %", print_c},
		{NULL, NULL},
	};
	int i = 0, j = 0, f_index;

	f_index = n;
	while (func_ops[i].type_arg)
	{
		if (s[n] == func_ops[i].type_arg[j])
		{
			if (func_ops[i].type_arg[j + 1] != '\0')
			{
				n++;
				j++;
			}
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			n = f_index;
		}
	}
	return (j);
}

/**
 * print_c - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_c(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handl_buf(buf, '%', i);
	return (1);
}
