/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelhansa <nelhansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:59:25 by nelhansa          #+#    #+#             */
/*   Updated: 2025/10/17 22:38:58 by nelhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *nptr)
{
	long int	numbre;
	int			positive;

	numbre = 0;
	positive = 1;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			positive = -positive;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		numbre = (numbre * 10) + (*nptr - 48);
		nptr++;
	}
	return (numbre * positive);
}
