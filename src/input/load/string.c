/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:09:16 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/09 13:59:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_private.h"

// time : O(n)
// space: O(1)
char	f_isspace(char s, const char *space)
{
	while (space != NULL && *space != '\0')
	{
		if (*space == s)
			return (1);
		space += 1;
	}
	return (0);
}

// time : O(n)
// space: O(1)
size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0')
	{
		i += 1;
		str += 1;
	}
	return (i);
}
