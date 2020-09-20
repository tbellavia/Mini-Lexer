/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:21:28 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/20 03:53:32 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

typedef struct	Token_s
{
	int	type;
	int value;
}				Token_t;

typedef struct	Interpreter_s
{
	Token_t token;
	int		index;
	char	*input;
}				Interpreter_t;

enum Type
{
	INT,
	OP,
	_EOF,
	ERR
};

enum Interpreter_err
{
	INTER_ERR_PARSING_INPUT
};

#endif