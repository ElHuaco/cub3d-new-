/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:38:15 by aleon-ca          #+#    #+#             */
/*   Updated: 2020/07/06 10:34:00 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_l
{
	void		*content;
	struct s_l	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *dest, const void *src, size_t n);
char			*ft_substr(char const *s, unsigned int st, size_t l);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strdup(const char *s1);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *n);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *n);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));

char			*ft_strndup(char *src, int n);
char			*ft_strunichr(int len, int c);
void			ft_strrep(char *str, int changed, int replacer);
char			*ft_itoabase(int n, char *base);
char			*ft_ultoabase(unsigned long  n, char *base);
int				ft_arrlen(char **arr);
int				ft_strcmp(char *s1, char *s2);
int				digit_number(int n, int basesize);
void			full_free(void **buff, int arr_len);
#endif
