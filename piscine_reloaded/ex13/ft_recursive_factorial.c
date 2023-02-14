/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:12:34 by mapostol          #+#    #+#             */
/*   Updated: 2021/10/28 16:52:07 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	a;

	if (nb < 0 || nb > 12)
		return (0);
	a = ft_recursive_factorial(nb - 1);
	if (a > 0)
		return (a * nb);
	else
		return (1);
}
