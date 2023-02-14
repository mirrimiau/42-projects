/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:54:19 by asuikkan          #+#    #+#             */
/*   Updated: 2022/10/28 11:54:21 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define RIGHTMOST_BYTE 0xFF

unsigned int	big_endian_converter(unsigned int src, int size)
{
	int				i;
	int				byte_pos;
	unsigned int	byte;
	unsigned int	ret;

	ret = 0;
	byte_pos = size - 1;
	i = -1;
	while (++i < size)
	{
		byte = 0;
		byte = (RIGHTMOST_BYTE << i * BITS_IN_BYTE & src);
		if (i < byte_pos)
			byte = byte << (byte_pos - i) * BITS_IN_BYTE;
		else
			byte = byte >> (i - byte_pos) * BITS_IN_BYTE;
		ret = ret | byte;
		byte_pos--;
	}
	return (ret);
}
