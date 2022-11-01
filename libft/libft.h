/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:12:41 by berdogan          #+#    #+#             */
/*   Updated: 2022/10/16 02:03:26 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_get
{
	int		status;
	char	*str;
	char	*rest;
}	t_gnl;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_printf(const char *src, ...);
int		ft_itoa_base(unsigned long long int nbr, int base, char format);
char	*get_next_line(int fd);
char	*ft_str_merge(char *container, char *buf);
char	*ft_container(int fd, char *container);
char	*ft_ret_line(char *container);
char	*ft_new_contaier(char *container);
int		ft_strlenn(char *str);
char	*ft_strchrr(char *s, int c);
char	*get_next_line_bonus(int fd);
int		ft_lenn(char *str);
int		ft_is_nl(char *str);
char	*ft_append(char *str1, char *str2);
char	*ft_move_rest(char *rest, char *to_free);
t_gnl	ft_seperate(char *str, int j);
int		ft_is_capital(char c);
int		ft_is_space(int c);
int		ft_atoi_base(char *str, int base);
int		ft_atoi_for_push_swap(const char *nptr);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *));
char	*ft_itoa_base_v2(int nbr, int base, char format);
char	*ft_revstr(char *str);
int		ft_max(int	*tab, int len);
#endif
