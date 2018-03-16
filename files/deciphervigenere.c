/****************************************************/
/*           "Decipher to Vigenere cipher"          */
/*                                                  */
/*                                                  */
/*                             by Aleksey Pavliuk   */
/*                             GitHub: lpavliuk     */
/*                                                  */
/****************************************************/

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_lower(char s, char d)
{
	char	k;
	int		n;
	int		i;

	n = 0;
	if (d >= 'A' && d <= 'Z')
		n = ((s - 'a') - (d - 'A') + 26) % 26;
	else if (d >= 'a' && d <= 'z')
		n = ((s - 'a') - (d - 'a') + 26) % 26;
	i = 'a' + n;
	k = i;
	ft_putchar(k);
}

void	ft_upper(char s, char d)
{
	char	k;
	int		n;
	int		i;

	n = 0;
	if (d >= 'A' && d <= 'Z')
		n = ((s - 'A') - (d - 'A') + 26) % 26;
	else if (d >= 'a' && d <= 'z')
		n = ((s - 'A') - (d - 'a') + 26) % 26;
	i = 'A' + n;
	k = i;
	ft_putchar(k);
}

void	ft_cipher(char **argv, int n)
{
	int i;

	i = 0;
	n = 0;	
	while (argv[1][i] != '\0')
	{
		if (argv[2][n] == '\0')
			n = 0;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			ft_lower(argv[1][i], argv[2][n]);
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			ft_upper(argv[1][i], argv[2][n]);
		else
			ft_putchar(argv[1][i]);
		i++;
		n++;
	}
}

int		main(int argc, char **argv)
{
	int n;
	
	n = 0;
	if (argv[2])
	{
		while (argv[2][n] != '\0')
		{
			if (argv[2][n] >= 'a' && argv[2][n] <= 'z')
				n = n;
			else if (argv[2][n] >= 'A' && argv[2][n] <= 'Z')
				n = n;
			else
			{
				argc = 2;
				break ;
			}
			n++;
		}
	}
	if (argc == 3)
		ft_cipher(argv, n);
	else
		write(2, "Error: Incorrect input or there is not a key!", 45);
	ft_putchar('\n');
	return (0);
}
