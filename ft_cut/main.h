#ifndef MAIN_H
# define MAIN_H

#include <stdlib.h>
#include <stdio.h>

# define RED "\033[0;31m"
# define GRE "\033[0;32m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define WHI "\033[0m"

typedef struct s_cut
{
	char		*before;
	char		*after;
	const char	*value;
	char		*new;
}	t_cut;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);

#endif
