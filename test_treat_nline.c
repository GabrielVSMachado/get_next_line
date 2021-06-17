#include "get_next_line.h"
#include <stdio.h>
static int	treat_new_line(char **src, char **dst, char *p_to_newline)
{
	char	*tmp;
	char	*new;
	int		len;

	len = (p_to_newline) - *src;
	tmp = ft_substr(*src, 0, (len));
	if (!tmp)
		return (-1);
	new = ft_strjoin(*dst, tmp);
	free(*dst);
	*dst = new;
	free(tmp);
	tmp = ft_substr(*src, len + 1, ft_strlen(*src));
	if (!tmp)
		return (-1);
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		tmp = NULL;
	}
	free(*src);
	*src = tmp;
	return (gnl_READ);
}

int main(void)
{
	char	*src;
	char	*dst;

	src = ft_strdup("gabriel vitor\n sales \n machado\n");
	dst = ft_strdup("");
	while (src)
		treat_new_line(&src, &dst, ft_strchr(src, '\n'));
	printf("%s\n", src);
	printf("%s\n", dst);
	free(src);
	free(dst);
	return (0);
}
