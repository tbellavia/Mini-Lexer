/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 00:15:19 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/21 01:43:15 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

int
_mult(int left, int right)
{
	return (left * right);
}

int
_add(int left, int right)
{
	return (left + right);
}
#include <stdio.h>
int
_div(int left, int right)
{
	if (right == 0)
	{
		_SetInter_Errno(INTER_ERR_ZERO_DIVISION);
		return (0);
	}
	return (left / right);
}

int
_mod(int left, int right)
{
	if (right == 0)
	{
		_SetInter_Errno(INTER_ERR_ZERO_DIVISION);
		return (0);
	}
	return (left % right);
}

int
_sub(int left, int right)
{
	return (left - right);
}

int
do_op(Token_t token, Token_t left, Token_t right)
{
	size_t index;

	index = 0;
	for (size_t index = 0; index < OP_CALLBACK_SIZE; index++)
	{
		if (op_callbacks[index].op == token.value)
			return (op_callbacks[index].callback(left.value, right.value));
	}
	_SetInter_Errno(INTER_ERR_UNKNOW_OP_TYPE);
	return (0);
}