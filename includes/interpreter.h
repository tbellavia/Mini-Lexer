/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 03:21:28 by bbellavi          #+#    #+#             */
/*   Updated: 2020/09/21 01:45:39 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include <stddef.h>

typedef struct	Token_s
{
	int	type;
	int value;
}				Token_t;

typedef struct	Interpreter_s
{
	Token_t token;
	size_t	index;
	char	*input;
}				Interpreter_t;

typedef struct	OpCallback_s
{
	char	op;
	int		(*callback)(int,int);
}				OpCallback_t;

enum Type
{
	INT,
	OP,
	_EOF,
	ERR
};

enum Interpreter_err
{
	INTER_ERR_PARSING_INPUT = 1,
	INTER_ERR_ZERO_DIVISION = 2,
	INTER_ERR_UNKNOW_OP_TYPE = 3
};

// symbol charset definition
# define SYM_CHARSET "+-%/*"

// define symbols
# define ADD	'+'
# define SUB	'-'
# define MOD	'%'
# define DIV	'/'
# define MULT	'*'

# define OP_CALLBACK_SIZE 5

int		eval(char *input);
int		_add(int, int);
int		_sub(int, int);
int		_div(int, int);
int		_mod(int, int);
int		_mult(int, int);
int		do_op(Token_t token, Token_t left, Token_t right);

// global variables
extern int			interpreter_errno;
static OpCallback_t	op_callbacks[OP_CALLBACK_SIZE] = {
	{ADD, _add},
	{SUB, _sub},
	{MOD, _mod},
	{DIV, _div},
	{MULT, _mult}
};

# define _InitInter_Errno(errval) int interpreter_errno = errval
# define _SetInter_Errno(errval) interpreter_errno = errval
# define _HasInter_Errno(errval) (errval == interpreter_errno)

#endif