/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:59:20 by mring             #+#    #+#             */
/*   Updated: 2024/10/14 10:47:27 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

// int	main(void)
// {
// 	char *str;
// 	str = "test";
// 	printf("nn:%s \n", strdup(str)); 
// 	printf("ft:%s \n", ft_strdup(str)); 
// }