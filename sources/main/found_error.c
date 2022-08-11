/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:15:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/08/11 15:48:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	found_error(void **pointer)
{
	if (!pointer)
	{
		ft_putstr_fd("Something went wrong\n", 2);
		exit(1);
	}
}
