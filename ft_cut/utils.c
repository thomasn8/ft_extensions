#include "main.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	char	*end;

	if (!s1 || !s2)
		return (NULL);
	start = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!start)
		return (NULL);
	end = start;
	while (*s1)
		*end++ = *s1++;
	while (*s2)
		*end++ = *s2++;
	*end = 0;
	return (start);
}

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	char	*start;
	char	*end;

	if (!s1 || !s2 || !s3)
		return (NULL);
	start = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (!start)
		return (NULL);
	end = start;
	while (*s1)
		*end++ = *s1++;
	while (*s2)
		*end++ = *s2++;
	while (*s3)
		*end++ = *s3++;
	*end = 0;
	return (start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			j++;
		i++;
	}
	substr = malloc(j * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	substr[j] = 0;
	i = 0;
	while (i < j)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	overflow;

	sign = 1;
	res = 0;
	overflow = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		overflow++;
	}
	if (overflow * sign > 10)
		return (-1);
	if (overflow * sign < -10)
		return (0);
	return (res * sign);
}
