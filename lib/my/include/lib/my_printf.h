/*
** EPITECH PROJECT, 2021
** INCLUDE/MY_PRINTF
** File description:
** Project's prototypes
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdint.h>
    #include <stddef.h>
    #define SYNTAX_ERROR 1
    #define FLAGS "#+ -0"
    #define SPECIFIERS "diuoxXpbcSs"
    #define LENGTH "hljzt"
    #define NO_PLUS "ouxXb"

typedef struct format_specifier {
    int flags[5];
    int width;
    int precision;
    char *length;
    char specifier;
    int len;
} fs_t;

typedef unsigned long long ull;

enum my_printf_length {MY_PRINTF_LENGTH_H = 0,
        MY_PRINTF_LENGTH_L = 1,
        MY_PRINTF_LENGTH_J = 2,
        MY_PRINTF_LENGTH_Z = 3,
        MY_PRINTF_LENGTH_T = 4,
        MY_PRINTF_LENGTH_HH = 5,
        MY_PRINTF_LENGTH_LL = 6};
enum flags {HASH = 0, PLUS = 1, SPACE = 2, MINUS = 3, ZERO = 4};

// Main
int my_printf(const char *format, ...);
int format_specifier(const char *format, int *i, fs_t *fs, va_list *argptr);

// Struct
fs_t *init_fs_t(void);
int free_fs_t(fs_t *fs);

// Format Specifier
int get_specifier_i(const char *str, int fs_i);
int get_fs(const char *str, int fs_i, int spe_i, fs_t *fs);
int my_printf_get_flags(char c, fs_t *fs, int *pos);
int reformat_flags(fs_t *fs);
int get_length_i(fs_t *fs);
int get_width(char c, fs_t *fs, int *pos);
int get_precision(char c, fs_t *fs, int *pos);
int get_length(char c, fs_t *fs);

// Errors
int my_printf_error(const char *str, int fs_i, int spe_i, fs_t *fs);
int error_wrong_char(const char *str, int fs_i, int spe_i, fs_t *fs);
int error_flags(const char *str, int fs_i, int spe_i, fs_t *fs);
int error_length_syntax(const char *str, int fs_i, int spe_i, fs_t *fs);
int error_wrong_length(const char *str, int fs_i, int spe_i, fs_t *fs);

// Print Errors
int print_char_error(const char *str, int fs_i, int spe_i, int i);
int print_length_error(const char *str, int fs_i, int spe_i, int i);
int print_wrong_length(const char *str, int fs_i, int spe_i);
int print_flags_error(const char *str, int fs_i, int spe_i);
int print_flags_order_error(const char *str, int fs_i, int spe_i, int *offset);

// Cast
int cast_param(va_list *argptr, fs_t *fs);
ull cast_signed(unsigned long long, fs_t *fs);
ull cast_unsigned(unsigned long long arg, fs_t *fs);
ull cast_ull(ull arg);
int cast_value(unsigned long long arg, fs_t *fs);

// Convert / Print arg
int print_value(unsigned long long arg, int i, fs_t *fs);
int print_mod(const char *format, int *i, int *len);
int convert_char(char c, fs_t *fs);
int print_string(char *str, fs_t *fs);
char *print_string_nprintable(char *str, fs_t *fs);
char *print_octal_char(const char *str, char *buffer, int non_printable);
char *convert_octal(ull arg);
char *convert_hex(ull arg);
char *convert_binary(ull arg);
char *convert_hex_upper(ull arg);
char *convert_pointer(ull arg);

// Apply special params
char *apply_flags(char *buffer, fs_t *fs);
char *apply_hash(char *buffer, fs_t *fs);
char *apply_plus(char *buffer, fs_t *fs);
char *apply_space(char *buffer, fs_t *fs);
char *apply_width(char *buffer, fs_t *fs);
char *apply_precision(char *buffer, fs_t *fs);
char *apply_string_precision(char *str, fs_t *fs);

// Add to lib
int my_strcontains(char const *str, char c);
int my_strcindex(char const *str, char c);
int my_char_isalpha(char c);
int my_char_isnum(char c);
int my_char_isprintable(char c);
char *my_strcchar(char *str, int i);
int my_nbrlen(unsigned long nb);
char *my_nbstr_unsigned(unsigned long nb);
char *my_nbstr_signed(long long nb);
char *my_strstrinsert(char *str, char c, int  n, int q);

// Tests
void redirect_all_stdout(void);

#endif//MY_PRINTF_H
