#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
enum returns
{
	gnl_ERROR = -1,
	gnl_EOF = 0,
	gnl_READ = 1,
}; 
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *string);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t ntype, size_t size);

#endif
