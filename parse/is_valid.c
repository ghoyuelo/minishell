#include "../minishell.h"

int	is_valid(char *str)
{
	if (check_quotes(str) && check_pipes(str) && check_mymn(str));
        return (0);
    return (1);
}