/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:18:20 by mring             #+#    #+#             */
/*   Updated: 2024/11/01 15:24:25 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	// cspdiuxX%
	// -0.# +
	// string loop logic
	count = 0;
	while (*str)
	{
		// if (*str == '%' && *str + 1 == '%')
		// count += write(1, "%", 1);
		if (*str == '%' && *str + 1 != '%')
			count += write(1, "%", 1);
		else
			write(1, str, 1);
		str++;
		if (count == -1)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (count);
}

/*
Logic breakdown for bonus:

#leading 0x, ignores + and - and space


*/

int	main(void)
{
	// you know how to use printf.
	// Use your brain and get that ft_printf going.
	// ft_printf("ft: Fuck the %s\n", "SYSTEM");
	printf("or: Fuck the %s\n", "SYSTEM");
	ft_printf("ft: Fuck the %s\n", "SYSTEM");
	ft_printf("space: Fuck the %s\n", "");
	// Expected: "Hex (lower) with #: 0x2a"
	printf("Hex (lower) with #:                 %4.x\n", 42);
	// Expected: "Hex (upper) with #: 0X2A"
	printf("Hex (upper) with #:                 %#X\n", 42);
	// Expected: "Space flag:  42" // works as standalone
	printf("Space flag:                         % d\n", 42);
	// Expected: "Negative with space: -42"
	printf("Negative with space:                % d\n", -42);
	// Expected: "Plus sign: +42"
	printf("Plus sign:                          %+d\n", 42);
	// Expected: "Negative with plus: -42" // + is ignored
	printf("Negative with plus:                 %+d\n", -42);
	// Expected: "Hex with + and #: 0x2a" // ignores + in hex
	printf("Hex with + and #:                   %#x\n", 42); // + unnecessary
	// Expected: "Hex with space and #: 0x2a" // ignores space in hex
	printf("Hex with space and #:               %#x\n", 42);
	// space unnecessary
	// Expected: "Space and plus: +42" // + overwrites space
	printf("Space and plus:                     %+d\n", 42);
	// space unnecessary
	// Expected: "Pointer with: 0x2a" // can ignore #
	printf("Pointer with #:                     %p\n", (void *)42);
	// Testing #, 0, and - in combination with %x and %X
	// Expected: "Hex with #:        0x2a"
	printf("Hex with #:                         %#10x\n", 42);
	// Expected: "Hex with 0 and #: 0x0000002a"
	printf("Hex with 0 and #:                   %#010x\n", 42);
	// Expected: "Hex left-aligned #: 0x2a      "
	printf("Hex left-aligned #:                 %-#10x\n", 42);
	// Testing +, space, -, and 0 with signed integers
	// Expected: "With space and width:      42"
	printf("With space and width:               % 10d\n", 42);
	// Expected: "Plus with width:        +42"
	printf("Plus with width:                    %+10d\n", 42);
	// Expected: "Left-aligned plus: +42      "
	printf("Left-aligned plus:                  %-+10d\n", 42);
	// Expected: "Zero-padded plus: +00000042"
	printf("Zero-padded plus:                   %+010d\n", 42);
	// Expected: "Negative with  zero: -00000042"
	printf("Negative with zero:                 %010d\n", -42);
	// Testing precision (.) with +, space, and #
	// Expected: "With precision: +0042"
	printf("With precision:                     %+05.4d\n", 42);
	// Expected: "With space and precision:   0042"
	printf("With space and precision:           % .4d\n", 42);
	// Testing # and precision with hex and integer
	// Expected: "Hex with precision #: 0x00002a"
	printf("Hex with precision #:               %#.8x\n", 42);
	// Expected: "Integer precision with 0 and width: 00000042"
	printf("Integer precision with 0 and width: %010.8d\n", 42);
	// Testing precision and width with -
	// Expected: "Left-aligned, precision: 0042      "
	printf("Left-aligned, precision:            %-10.4d\n", 42);
	// Expected: "Pointer with precision: 0x0000002a"
	printf("Pointer with precision:             %7.3p\n", (void *)42);
	// that prints, starting from and including 0x,
	// X amount of 0. 8? 0x000000. 2? 0x. 4? 0x00.
	// the number before the . is the padding for the entire strlen
	// if the min length is above the number its ignored
	// if the number is > len, it prints spaces to the left.
	// Outputs "    %" with four spaces padding the % on the left.
	printf("|%5%\n");
	// Outputs "%    " with four spaces padding on the right due to the left alignment.
	printf("%-5%|\n");
}

/*
	// you know how to use printf.
	// Use your brain and get that ft_printf going.
	// ft_printf("ft: Fuck the %s\n", "SYSTEM");
	printf("or: Fuck the %s\n", "SYSTEM");
	ft_printf("ft: Fuck the %s\n", "SYSTEM");
	// Expected: "Hex (lower) with #: 0x2a"
	printf("%%#x:     %#x\n", 42);
	// Expected: "Hex (upper) with #: 0X2A"
	printf("%%#X:     %#X\n", 42);
	// Expected: "Space flag:  42" // works as standalone
	printf("%% d:     % d\n", 42);
	// Expected: "Negative with space: -42"
	printf("%% d:     % d\n", -42);
	// Expected: "Plus sign: +42"
	printf("%%+d:     %+d\n", 42);
	// Expected: "Negative with plus: -42" // + is ignored
	printf("%%+d:     %+d\n", -42);
	// Expected: "Hex with + and #: 0x2a" // ignores + in hex
	printf("%%#d:     %#x\n", 42); // + unnecessary
	// Expected: "Hex with space and #: 0x2a" // ignores space in hex
	printf("%%#x:     %#x\n", 42); // space unnecessary
	// Expected: "Space and plus: +42" // + overwrites space
	printf("%%+d:     %+d\n", 42); // space unnecessary
	// Expected: "Pointer with: 0x2a" // can ignore #
	printf("%%p:      %p\n", (void *)42);
	// Testing #, 0, and - in combination with %x and %X
	// Expected: "Hex with #:        0x2a"
	printf("%%#10x:   %#10x\n", 42);
	// Expected: "Hex with 0 and #: 0x0000002a"
	printf("%%#010x:  %#010x\n", 42);
	// Expected: "Hex left-aligned #: 0x2a      "
	printf("%%-#10x:  %-#10x\n", 42);
	// Testing +, space, -, and 0 with signed integers
	// Expected: "With space and width:      42"
	printf("%% 10d:   % 10d\n", 42);
	// Expected: "Plus with width:        +42"
	printf("%%+10d:   %+10d\n", 42);
	// Expected: "Left-aligned plus: +42      "
	printf("%%-+10d:  %-+10d\n", 42);
	// Expected: "Zero-padded plus: +00000042"
	printf("%%+010d:  %+010d\n", 42);
	// Expected: "Negative with zero: -00000042"
	printf("%%010d:   %010d\n", -42);
	// Testing precision (.) with +, space, and #
	// Expected: "With precision: +0042"
	printf("%%+05.4d: %+05.4d\n", 42);
	// Expected: "With space and precision:   0042"
	printf("%% .4d:   % .4d\n", 42);
	// Testing # and precision with hex and integer
	// Expected: "Hex with precision #: 0x00002a"
	printf("%%#.8x:   %#.8x\n", 42);
	// Expected: "Integer precision with 0 and width: 00000042"
	printf("%%010.8d: %010.8d\n", 42);
	// Testing precision and width with -
	// Expected: "Left-aligned, precision: 0042      "
	printf("%%-10.4d: %-10.4d\n", 42);
	// Expected: "Pointer with precision: 0x0000002a"
	printf("%%7.3p:   %7.3p\n", (void *)42);
	// that prints, starting from and including 0x,
	// X amount of 0. 8? 0x000000. 2? 0x. 4? 0x00.
	// the number before the . is the padding for the entire strlen
	// if the min length is above the number its ignored
	// if the number is > len, it prints spaces to the left.
	*/

// Chapter I
// Introduction
// You will discover a popular and versatile C function: printf().
// You will discover variadic functions in C.
// The key to a successful ft_printf is a well-structured and extensible code.
// Once this assignment passed, you will be allowed to add your
// ft_printf() to your libft so you can use it in your school C projects.
// 2
// Chapter II
// Common Instructions
// • Your project must be written in C.
// • Your project must be written in accordance with the Norm. If you have bonus
// files/functions,
// 	they are included in the norm check and you will receive a 0 if there
// is a norm error inside.
// • Your functions should not quit unexpectedly apart from undefined behaviors.
// • All heap allocated memory space must be properly freed when necessary.
// No leaks will be tolerated.

// • If your project allows you to use your libft,
// 	you must copy its sources and its
// associated Makefile in a libft folder with its associated Makefile. Your project’s
// Makefile must compile the library by using its Makefile then compile the project.

// Program name libftprintf.a
// Turn in files Makefile, *.h, * .h, *.c, * *.c
//  Makefile NAME, all, clean, fclean, re
//  External functs.
//  malloc, free, write, va_start, va_arg, va_copy, va_end
//  Libft authorized Yes
//  Description Write a library that contains ft_printf(), a
//  function that will mimic the original	printf(void)
//  You have to recode the printf() function from libc.
//  The prototype of ft_printf() is:
//  int										ft_printf(const char *, ...);
//  Here are the requirements:
//  • Don’t implement the buffer management of the original printf().
//  • Your function has to handle the following conversions: cspdiuxX%
//  • Your function will be compared against the original printf().
//  • You must use the command ar to create your library.
//  Using the libtool command is forbidden.
//  • Your libftprintf.a has to be created at the root of your repository.
//  5
//  ft_printf Because ft_putnbr() and ft_putstr() aren’t enough
//  You have to implement the following conversions:
//  • %c Prints a single character.
//  • %s Prints a string (as defined by the common C convention).
//  • %p The void * pointer argument has to be printed in hexadecimal format.
//  • %d Prints a decimal (base 10) number.
//  • %i Prints an integer in base 10.
//  • %u Prints an unsigned decimal (base 10) number.
//  • %x Prints a number in hexadecimal (base 16) lowercase format.
//  • %X Prints a number in hexadecimal (base 16) uppercase format.
//  • %% Prints a percent sign.

//  Bonus:
//  • Manage any combination of the following flags: ’-0.’ and the field minimum width
//  under all conversions.
//  • Manage all the following flags: ’# +’ (Yes, one of them is a space)

//  If you plan to complete the bonus part, think about the
//  implementation of your extra features from the start. This way,
//  you will avoid the pitfalls of a naive approach.
