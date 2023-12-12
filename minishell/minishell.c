/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:34:40 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/11/29 14:34:40 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"





//COMILLAS dobles y simples sin cerrar

char	*search(char *str, char c)
{
	if (*str == c)
	{
		str++;
		while (*str != c && *str)
			str++;
	}
	return (str);
}

char	*shearch_quotes(char *str)
{
	str = search(str, '"');
	str = search(str, 39);
	return (str);
}

int	closed_quotes(char *str)
{
	while (*str)
	{
		str = search_quotes(str);
		if (*str == 0)
		{
			return (0);
		}
		str++;
	}
    print_error("Error: Unclosed quotes.");
	return (1);
}

static int	check_content(char *str, char c)
{
	if (prepcontain(str, c))
	{
		//print_error("Error: I do not interpret the special character %c\n", c);
		printf("Error: I do not interpret the special character %c\n", c);
		return (0);
	}
	return (1);
}

// No se permiten caracteres especiales dentro de las comillas 

int	check_forbiden(char *str)
{
	return (closed_quotes(str)
		&& check_content(str, '(')
		&& check_content(str, ')')
		&& check_content(str, '*')
		&& check_content(str, ';')
		&& check_content(str, 92));  // 92 es '\' en ascii 		
}