/****************************************************/
/*           "Decipher to Caesar cipher"            */
/*                                                  */
/*                                                  */
/*                             by Aleksey Pavliuk   */
/*                             GitHub: lpavliuk     */
/*                                                  */
/****************************************************/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1); 
}

int		ft_atoi(char *str)
{
	int	i;
	int	n;
	int num;

	i = 0;
	n = 1;
	num = 0;
	while ((str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t') && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && !(str[i - 1]))
			n = -1;
		else if (str[i] == '+' && !(str[i - 1]))
			n = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (num * n);
}

void	ft_lower(char s, int k)
{
	int		i;
	int		n;
	char	d;

	i = s - 'a';
	n = (i - k + 26) % 26;
	i = 'a' + n;
	d = i;
	ft_putchar(d);
}

void	ft_upper(char s, int k)
{
	int		i;
	int		n;
	char	d;

	i = s - 'A';
	n = (i - k + 26) % 26;
	i = 'A' + n;
	d = i;
	ft_putchar(d);
}

int		check(char *str)
{
	int k;
	int n;

	n = 0;
	k = -1;
	while (str[n] != '\0')
	{
		if (str[n] < '0' || str[n] > '9')
			return (k);
		n++;
	}
	k = ft_atoi(str);
	return (k);
}

int		main(int argc, char **argv)
{
	int i;
	int k;

	i = 0;
	if (argv[2])
		k = check(argv[2]);
	if (argc == 3 && k >= 0 && k <= 26)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				ft_lower(argv[1][i], k);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				ft_upper(argv[1][i], k);
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	else if (k < 0 || k > 26)
		write(2, "Error: Key can be only between numbers 0 and 26!", 48);
	else
		write(2, "Error: Incorrect input or there is not a key!", 45);
	ft_putchar('\n');
	return (0);
}
