/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 08:28:52 by gekang            #+#    #+#             */
/*   Updated: 2020/07/11 10:54:37 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **a, char **b) // why 2 asterics? because it's pointer to string
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i])
			i++;
	printf("comparing %c and %c equals %d", str1[i], str2[i], str1[i] - str2[i]);
	return (str1[i] - str2[i]);
}


void	ft_sort_params(char **array, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			printf("%d\n", ft_strcmp(array[i], array[j]));
			if (ft_strcmp(array[i], array[j]) > 0)
			{
				//printf("check");
				ft_swap(&array[i], &array[j]); // swap the address
				continue;
			}
			j++;
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	int i;

	if (argc > 2)
		ft_sort_params(argv, argc - 1); // why just argv, not &argv or *argv?
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}
