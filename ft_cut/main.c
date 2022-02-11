#include "main.h"

// string index_start_the_cut len_of_cut
char	*ft_cut_strnstr(const char *str, unsigned int start, unsigned int len)
{
	t_cut	piece;
	int		max_len_of_cut;
	int		len_of_cut;

	max_len_of_cut = ft_strlen(str);
	len_of_cut = start + len;
	if (len_of_cut > max_len_of_cut)
		len_of_cut = max_len_of_cut;
	piece.before = ft_substr(str, 0, start);
	piece.after = ft_substr(str, start + len, ft_strlen(&str[len_of_cut]));
	piece.new = ft_strjoin(piece.before, piece.after);
	free(piece.before);
	free(piece.after);
	return (piece.new);
}

// string string_to_transplant index_start_to_transplant len_of_cut
char	*ft_replace_strnstr(const char *str, const char *graft,
			unsigned int start, unsigned int len)
{
	t_cut	piece;
	int		max_len_of_cut;
	int		len_of_cut;

	max_len_of_cut = ft_strlen(str);
	len_of_cut = start + len;
	if (len_of_cut > max_len_of_cut)
		len_of_cut = max_len_of_cut;
	piece.value = graft;
	piece.before = ft_substr(str, 0, start);
	piece.after = ft_substr(str, start + len, ft_strlen(&str[len_of_cut]));
	if (piece.value)
	{
		piece.new = ft_strjoin_3(piece.before, piece.value, piece.after);
		len = ft_strlen(piece.value);
	}
	else
	{
		piece.new = ft_strjoin(piece.before, piece.after);
		len = 0;
	}
	free(piece.before);
	free(piece.after);
	return (piece.new);
}


int	main(int ac, char **av)
{
	char	**str_split;
	int		i;
	int		start;
	int		len;
	char	*new;
	
	if (ac == 4)
	{
		start = atoi(av[2]);
		len = atoi(av[3]);
		new = ft_cut_strnstr(av[1], start, len);
		printf("New str after cut: ");
		printf("|%s%s%s|\n", GRE, new, WHI);
	}
	else if (ac == 5)
	{
		start = atoi(av[3]);
		len = atoi(av[4]);
		new = ft_replace_strnstr(av[1], av[2], start, len);
		printf("New str after replacement: ");
		printf("|%s%s%s|\n", GRE, new, WHI);
	}
	else
	{
		printf("usage:	./a.out string index_start_the_cut len_of_cut\n");
		printf("%sexp:	%s./a.out '0123456789' 5 4 %sremoves '5678' and returns '012349'%s\n", YEL, BLU, YEL, WHI);
		printf("usage:	./a.out string string_to_transplant index_start_to_transplant len_of_cut\n");
		printf("%sexp:	%s./a.out '0123456789' 'abcd' 5 2 %sremoves '56', transplants 'abcd' at index 5 and returns '01234abcd789'%s\n", YEL, BLU, YEL, WHI);
	}
	return (0);
}
