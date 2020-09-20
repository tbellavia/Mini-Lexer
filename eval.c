/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:34:47 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/20 23:35:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "interpreter.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int result = eval(argv[1]);
		
		printf("> %i\n", result);
	}
	return (0);
}