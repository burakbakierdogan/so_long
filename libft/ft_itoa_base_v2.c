/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:48:29 by berdogan          #+#    #+#             */
/*   Updated: 2022/10/11 04:48:29 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int nbr, int base)
{
	int	index;

	index = 0;
	if (nbr == 0)
		return (0);
	if (nbr < 0)
	{
		index++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= base;
		index++;
	}
	return (index);
}

static	char	*ft_int_min_2(int base)
{
	if (base == 8)
		return (ft_strdup("-104134211162"));
	if (base == 9)
		return (ft_strdup("-5478773672"));
	if (base == 10)
		return (ft_strdup("-2147483648"));
	if (base == 11)
		return (ft_strdup("-A02220282"));
	if (base == 12)
		return (ft_strdup("-4BB2308A8"));
	if (base == 13)
		return (ft_strdup("-282BA4AAB"));
	if (base == 14)
		return (ft_strdup("-1652CA932"));
	if (base == 15)
		return (ft_strdup("-C87E66B8"));
	if (base == 16)
		return (ft_strdup("-80000000"));
	else
		return (NULL);
}

static	char	*ft_int_min(int base)
{
	if (base == 2)
		return (ft_strdup("-10000000000000000000000000000000"));
	if (base == 3)
		return (ft_strdup("-12112122212110202102"));
	if (base == 4)
		return (ft_strdup("-2000000000000000"));
	if (base == 5)
		return (ft_strdup("-13344223434043"));
	if (base == 6)
		return (ft_strdup("-553032005532"));
	if (base == 7)
		return (ft_strdup("-104134211162"));
	else
		return (ft_int_min_2(base));
}

static	char	*ft_get_the_string(int nbr, int base, char format, int len)
{
	char	*str;

	str = (char *) ft_calloc (len, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	len -= 2;
	while (len >= 0 && nbr)
	{
		str[len] = (nbr % base) + 48;
		if (nbr % base > 9 && format == 'X')
			str[len] = ((nbr % base) - 10) + 'A';
		else if (nbr % base > 9 && format == 'x')
				str[len] = ((nbr % base) - 10) + 'a';
		len--;
		nbr /= base;
	}
	return (str);
}

char	*ft_itoa_base_v2(int nbr, int base, char format)
{
	int		len;

	if (nbr == INT_MIN)
		return (ft_int_min(base));
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_len(nbr, base) + 1;
	return (ft_get_the_string(nbr, base, format, len));
}
