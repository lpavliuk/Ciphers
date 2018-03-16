/*****************************************************/
/*                   "Atbash"                        */
/*                                                   */
/*                                                   */
/*                             by Aleksey Pavliuk    */
/*                             GitHub: lpavliuk      */
/*                                                   */
/*****************************************************/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_lower(char s)
{
	int		i;
	int		n;
	char	d;

	i = 'z' - s;
	n = 'a' + i;
	d = n;
	ft_putchar(d);	
}

void	ft_upper(char s)
{
	int		i;
	int		n;
	char	d;

	i = 'Z' - s;
	n = 'A' + i;
	d = n;
	ft_putchar(d);	
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				ft_lower(argv[1][i]);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				ft_upper(argv[1][i]);
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	else
		write (2, "Error: Incorrect input!", 24);
	ft_putchar('\n');
	return (0);
}
