/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:09 by mring             #+#    #+#             */
/*   Updated: 2024/10/22 15:26:16 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	result = ft_strdup(s);
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}

// the result string called result
// i for iterating
// first duplicate and allocate the string as result
// if allocation failed, return NULL obviously
// while it has no existential crisis
// assign the new char of the current position in string
// with the char that was run through the function.
// return, result.