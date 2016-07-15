/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:14:36 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 16:38:43 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <libc.h>
# include <string.h>
# include <stdarg.h>
# define BUFF_SIZE 32
# define UL unsigned long
# define ULL unsigned long long
# define ST size_t
# define UIM uintmax_t
# define UI unsigned int
# define LUI long unsigned int

typedef struct	s_flags
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		padding;
	int		offset;
	int		negative;
	int		is_num;
	int		use_hasho;
	int		use_hashx;
	int		address;
	int		precision;
	int		zeroes;
	int		is_string;
	int		is_long;
	int		is_short;
	int		z;
	int		j;
	char	pad;
	int		wide;
}				t_flags;

typedef struct	s_list
{
	void			*data;
	int				op_pos;
	struct s_list	*next;
}				t_list;

void			ft_lstpushpop(t_list **a, t_list **b);

void			ft_lstrot(t_list **first, int num);

void			ft_lstrotrev(t_list **first, int num);

void			ft_lstpush(t_list **first, t_list *new_node);

t_list			*ft_lstpop(t_list **first);

void			ft_lstswap(t_list *first);

t_list			*ft_lstnew(void *data);

int				ft_printf(const char *format_str, ...);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

size_t			ft_strlenwide(wchar_t *s);

int				ft_padstr(char *str, t_flags flags);

int				ft_padstrwide(wchar_t *str, t_flags flags);

int				ft_padchar(char chr, t_flags flags);

t_flags			ft_getflags(t_flags flags, char *c);

int				ft_uox(char *cr, va_list args, t_flags flags);

int				ft_di(char *cr, va_list args, t_flags flags);

char			*ft_convert(uintmax_t num, int base, int code);

char			*ft_convert_u(size_t num, int base, int code);

int				get_next_line(const int fd, char **line);

void			*ft_memset(void *s, int c, size_t length);

void			ft_bzero(void *s, size_t n);

void			*ft_memcpy(void *const dest, void const *src, size_t n);

void			*ft_memccpy(void *const dest, void const *src, int c, size_t n);

void			*ft_memmove(void *dst, void const *src, size_t length);

void			*ft_memchr(void const *s, int c, size_t n);

int				ft_memcmp(void const *s1, void const *s2, size_t n);

size_t			ft_strlen(char const *str);

char			*ft_strdup(char const *src);

char			*ft_strcpy(char *dest, char const *src);

char			*ft_strncpy(char *dest, char const *src, size_t length);

char			*ft_strcat(char *const s1, char const *s2);

char			*ft_strncat(char *const s1, char const *s2, size_t n);

size_t			ft_strlcat(char *const dest, char const *src, size_t size);

char			*ft_strchr(char const *str, int c);

char			*ft_strrchr(char const *str, int c);

char			*ft_strstr(char const *big, char const *little);

char			*ft_strnstr(char const *big, char const *little, size_t length);

int				ft_strcmp(char const *s1, char const *s2);

int				ft_strncmp(char const *s1, char const *s2, size_t n);

int				ft_atoi(char const *str);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_toupper(int c);

int				ft_tolower(int c);

void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);

char			*ft_strnew(size_t size);

void			ft_strdel(char **as);

void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strequ(char const *s1, char const *s2);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s);

char			**ft_strsplit(char const *s, char c);

char			*ft_itoa(int n);

int				ft_putchar(char c);

int				ft_putstr(char const *s);

void			ft_putstrwide(wchar_t *c);

void			ft_putendl(char const *s);

void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char const *s, int fd);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr_fd(int n, int fd);

#endif
