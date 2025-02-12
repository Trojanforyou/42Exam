/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:29:51 by msokolov          #+#    #+#             */
/*   Updated: 2025/02/04 17:07:31 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

void	search_and_replace(int argc, char **argv)
{
	int i = 0;
	if (argc != 4)
		write (1, "\n", 1);
	if (argc == 4)
	{
		if (argv[2][1] != '\0' && argv[3][1] != '\0')
		{
			write (1, "\n", 1);
			return ;
		}
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
			{
				write (1, &argv[3][0], 1);
			}
			else
				write (1, &argv[1][i], 1);
			i++;
		}
		write (1, "\n", 1);
	}
}
int main (int argc, char **argv)
{
	search_and_replace(argc, argv);
	return (0);
}
