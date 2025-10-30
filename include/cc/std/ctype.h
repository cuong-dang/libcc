#ifndef _CTYPE
#define _CTYPE

/*
 * A minimal implementation of ctype.h.
 * Minimal means that it only supports the minimal C locale, i.e., only
 * ASCII. In addition, it does not support extra control or punctuation
 * characters, even though they are allowed in the C locale. Finally,
 * control characters only include form feed, new line, carriage return,
 * horizontal tab, vertical tab, backspace, and alert (bell). Other control
 * characters in ASCII code range 0 to 31 are not anything.
 */

/*
 * The macro implementations are omitted. Functionally, macros are
 * sufficient. However, the standard expects functions. Thus, macros
 * become performance optimization. Though libcc is a serious and complete
 * implementation, I find that the performance reason does not justify the
 * double-implementations.
 */

/*
 * The order of the definitions is based on the helpful graph which shows
 * how the character classification functions relate to each other in
 * Plauger and Brodie, Standard C. The order is roughly from leaves to
 * root.
 */
int isupper(int c);
int islower(int c);
int isalpha(int c);
int isdigit(int c);
int isxdigit(int c);
int isalnum(int c);
int ispunct(int c);
int isgraph(int c);
int isprint(int c);
int isspace(int c);
int iscntrl(int c);

#endif
