/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:29:29 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 12:54:00 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns a part of a string - string, start, length
#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
