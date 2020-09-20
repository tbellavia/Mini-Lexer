/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:34:47 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/21 01:02:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "interpreter.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int result = eval(argv[1]);
		
		if (_HasInter_Errno(INTER_ERR_ZERO_DIVISION))
			printf("> ZeroDivisionError\n");
		else
			printf("> %i\n", result);
	}
	return (0);
}