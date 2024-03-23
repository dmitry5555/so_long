/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:34:33 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 12:53:58 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns string A length
#include "so_long.h"

size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
