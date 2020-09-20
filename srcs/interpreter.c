/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:24:12 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/21 00:42:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "interpreter.h"

static Token_t
get_next_token(Interpreter_t *inter)
{
	const size_t	len = strlen(inter->input);
	char			current_char;
	Token_t			tok;

	if (inter->index > len - 1)
		return ((Token_t){_EOF, 0});


	// skip whitespaces
	while (isspace(inter->input[inter->index]) && inter->index < len - 1)
		inter->index++;

	current_char = inter->input[inter->index];
	
	if (isdigit(current_char))
	{
		tok = (Token_t){INT, atoi(&inter->input[inter->index])};
		// skip digits so we don't evaluate next digit if number has multi digits
		while (isdigit(inter->input[inter->index]) && inter->index < len - 1)
			inter->index++;
		return (tok);
	}
	else if (strchr(SYM_CHARSET, current_char))
		tok = (Token_t){OP, current_char};
	else
		tok = (Token_t){ERR, 0};
	
	inter->index++;

	return (tok);
}

static int
eat(Interpreter_t *inter, int token_type)
{
	if (token_type == inter->token.type)
		inter->token = get_next_token(inter);
	else
		return (INTER_ERR_PARSING_INPUT);
	return (0);
}

int
eval(char *input)
{
	Interpreter_t	inter = (Interpreter_t){.index = 0, .input = input};
	Token_t			left;
	Token_t			right;
	Token_t			op;

	inter.token = get_next_token(&inter);
	left = inter.token;
	if (eat(&inter, INT) != 0)
		return (0);
	
	op = inter.token;
	if (eat(&inter, OP) != 0)
		return (0);
	
	right = inter.token;
	if (eat(&inter, INT) != 0)
		return (0);

	return (do_op(op, left, right));
}