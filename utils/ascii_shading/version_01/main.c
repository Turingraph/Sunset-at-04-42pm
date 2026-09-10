#include"unistd.h"
#include"stdlib.h"

char	f_isspace(char s, char *space)
{
	size_t	i;

	i = 0;
	while (*space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
		i += 1;
	}
	return (0);
}

/*
int	main(void)
{
	size_t	i;
	char	*all_dict;
	char	*std_dict;

	all_dict = "@MW#BNHRQD0896OKAPgbdpqmeawEZSGUVX&FI5$4khyoY%32CTJL71{}?*[]=<>ftsznux+jlicvr()|\\/\"^!~;-_:,.'` ";
	// std_dict = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";
	std_dict = " `.-':_,^=;><+!rc*z/?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
	i = 0;
	while (all_dict[i] != '\0')
	{
		if (f_isspace(all_dict[i], std_dict) == 0)
			write(1, all_dict + i, 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}
*/

int	main(void)
{
	size_t	i;
	char	*my_dict;
	char	*std_dict;
	char	*their_dict;
	char	*mir_dict;

	mir_dict = "ASLbpsuaf[({</6";
	my_dict = " `'.,:_-;~!^\"/\\|()rvcilj+xunzstf><=[]*?{}17LJTC23%Yoyhk4$5IF&XVUGSZEwaemqpdbgPAKO6980DQRHNB#WM@";
	std_dict = " .'`^\",:;Il!i><~+_-?[]{}1()|\\/tfjrxnuvczs=7T23y45FXYUJCLQ0OZmwqpdbkhaoVGSEegPA*#MW&8%K69DRHNB@$";
	their_dict = " `.-~'\":_,^=;><+!rc*\\/z?sLTv(J7)|FiC{}fI31tluneoZ5Yxjya[]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
	i = 0;
	while (my_dict[i] != '\0')
	{
		if (f_isspace(my_dict[i], mir_dict) == 0)
			write(1, my_dict + i, 1);
		i += 1;
	}
	write(1, "\n", 1);
	i = 0;
	while (std_dict[i] != '\0')
	{
		if (f_isspace(std_dict[i], mir_dict) == 0)
			write(1, std_dict + i, 1);
		i += 1;
	}
	write(1, "\n", 1);
	i = 0;
	while (their_dict[i] != '\0')
	{
		if (f_isspace(their_dict[i], mir_dict) == 0)
			write(1, their_dict + i, 1);
		i += 1;
	}
	write(1, "\n", 1);
	return (0);
}

/*
cc -Wall -Wextra -Werror main.c
*/