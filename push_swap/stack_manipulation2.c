/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:22:39 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/16 17:22:40 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_input_s(int *i, char input[BUF],
			char a[BUF][12], char b[BUF][12])
{
	(*i)++;
	if (input[*i] == 'a' && input[*i + 1])
		swap(a);
	if (input[*i] == 'b' && input[*i + 1])
		swap(b);
	if (input[*i] == 's' && input[*i + 1])
	{
		swap(a);
		swap(b);
	}
}

void	resolve_input_r(int *i, char input[BUF],
			char a[BUF][12], char b[BUF][12])
{
	(*i)++;
	if (input[*i] == 'r')
	{
		(*i)++;
		if (input[*i] == 'a' && input[*i + 1])
			reverse_rotate(a);
		if (input[*i] == 'b' && input[*i + 1])
			reverse_rotate(b);
		if (input[*i] == 'r' && input[*i + 1])
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
	}
	else if (input[*i] == 'a' && input[*i + 1])
		rotate(a);
	else if (input[*i] == 'b' && input[*i + 1])
		rotate(b);
	else if (input[*i] == 'r' && input[*i + 1])
	{
		rotate(a);
		rotate(b);
	}
}

void	resolve_input_p(int *i, char input[BUF],
			char a[BUF][12], char b[BUF][12])
{
	(*i)++;
	if (input[*i] == 'a' && input[*i + 1])
		put(a, b);
	if (input[*i] == 'b' && input[*i + 1])
		put(b, a);
}

int	resolve_input(char input[BUF], char a[BUF][12], char b[BUF][12])
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 's')
			resolve_input_s(&i, input, a, b);
		else if (input[i] == 'p')
			resolve_input_p(&i, input, a, b);
		else if (input[i] == 'r')
			resolve_input_r(&i, input, a, b);
		else if (input[i] == 4)
		{
			return (2);
		}
		else
			return (0);
		i += 2;
	}
	return (1);
}

int	test_bounds(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	if (ft_strequ(temp, "-2147483648"))
		return (1);
	if (temp[0] == '-')
		temp++;
	if (ft_strlen(temp) < 10)
		return (1);
	if (ft_strcmp(temp, "2147483647") > 0)
		return (0);
	return (1);
}
