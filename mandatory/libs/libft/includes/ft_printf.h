/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:27:54 by dpotsch           #+#    #+#             */
/*   Updated: 2025/05/02 15:05:04 by dpotsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define NULL_PTR_STR "(nil)"
# define BASE_LO "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
# define PRINT_BUFFER_SIZE 128

// STRUCTS
typedef struct s_flags
{
	bool	left_justify;
	bool	zero_padding;
	bool	alternate_form;
	bool	explicit_sign;
	bool	space;
	bool	precision;
}			t_flags;

typedef struct s_type
{
	bool	c;
	bool	s;
	bool	p;
	bool	d;
	bool	i;
	bool	u;
	bool	x_lo;
	bool	x_up;
}			t_type;

typedef struct s_format_specifier
{
	t_flags	flags;
	int		width;
	int		precision;
	t_type	type;
	bool	invalid;
	bool	invalid_eol;
	bool	percent;
	int		fd;
}			t_format_specifier;

typedef struct s_print_buff_handler
{
	char	buff[PRINT_BUFFER_SIZE];
	size_t	i;
	bool	is_empty;
}			t_print_buff_handler;

// MAIN FUNCTION
int			ft_printf(const char *format, ...) \
__attribute__((format(printf, 1, 2)));
int			ft_eprintf(const char *format, ...) \
__attribute__((format(printf, 1, 2)));
int			ft_fprintf(const int fd, const char *format, ...) \
__attribute__((format(printf, 2, 3)));

// UTILS
void		reset_format_specifier(t_format_specifier *fs);
void		get_num_len(long long num, int *result);
int			get_num_len_formatted(long long num, int numlen,
				t_format_specifier *fs);
int			get_num_len_formatted_p(size_t num, int numlen,
				t_format_specifier *fs);
int			get_str_precision(char *str, t_format_specifier *fs);

void		init_format_specifier(t_format_specifier *fs, int file_descriptor);
int			apply_format(va_list *parg, t_format_specifier *fs);
void		check_format_specifiers(const char *format, size_t *i,
				t_format_specifier *fs);
int			write_default(const char *format, size_t *i, t_format_specifier *fs,
				int i_percent);

// PUTNBR
void		ft_printf_putnbr(long long n, int fd);
int			putnbr_hex(size_t number, const char *base, const int fd);
int			get_hex_len(size_t number);

// FORMAT CHECK
void		check_flags(const char *format, size_t *i, t_format_specifier *fs);
void		check_width(const char *format, size_t *i, t_format_specifier *fs);
void		check_precision(const char *format, size_t *i,
				t_format_specifier *fs);
void		check_specifier(const char *format, size_t *i,
				t_format_specifier *fs);
void		validate_format(t_format_specifier *fs);

// OUTPUT
int			output_c(int c, t_format_specifier *fs);
int			output_s(char *str, t_format_specifier *fs);
int			output_p(void *ptr, t_format_specifier *fs);
int			output_d(int num, t_format_specifier *fs);
int			output_i(int num, t_format_specifier *fs);
int			output_u(unsigned int num, t_format_specifier *fs);
int			output_x_lo(unsigned int num, t_format_specifier *fs);
int			output_x_up(unsigned int num, t_format_specifier *fs);
int			output_percent(t_format_specifier *fs);

// FORMATTING
int			left_justify(int strlen, t_format_specifier *fs);
int			right_justify(int strlen, t_format_specifier *fs);
int			zero_padding(long long num, int numlen_raw, t_format_specifier *fs);
int			add_sign(long long *num, t_format_specifier *fs);

// PRINT BUFFER
int			add_to_buffer(int fd, const char *str, size_t len);
void		flush_print_buffer(int fd);
#endif
