/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:37:46 by mring             #+#    #+#             */
/*   Updated: 2024/10/10 14:14:25 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize > src_len + 1)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

// int main(void)
// {
// 	char str[] = "random string";
// 	char str2[15];
// 	printf("str1: %s\nstr2: %s\n", str, str2);
// 	ft_strlcpy(str2, str, 9);
// 	printf("str1: %s\nstr2: %s\n", str, str2);
// }