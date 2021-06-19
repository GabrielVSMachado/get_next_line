#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*final_str;
	int		counter;
	int		len_f_str;

	if (!s1 || !s2)
		return (NULL);
	len_f_str = (ft_strlen(s1) + ft_strlen(s2) + 1);
	final_str = (char *)malloc(sizeof(char) * len_f_str);
	if (final_str == NULL)
		return (NULL);
	counter = 0;
	while (*s1)
		final_str[counter++] = *s1++;
	while (*s2)
		final_str[counter++] = *s2++;
	final_str[counter] = '\0';
	return (final_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	counter;
	size_t	len_alloc;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < (size_t)start)
		len_alloc = 1;
	else if (len_s - (size_t)start > len)
		len_alloc = len;
	else
		len_alloc = len_s - (size_t)start;
	substr = (char *)malloc(sizeof(char) * (len_alloc + 1));
	if (substr == NULL)
		return (NULL);
	counter = 0;
	while (counter < len && (len_s > (size_t)(start + counter)))
	{
		substr[counter] = s[start + counter];
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	counter;

	counter = 0;
	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (str[counter])
	{
		if (str[counter] == (unsigned char) c)
			return ((char *)&str[counter]);
		counter++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		counter_src;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	counter_src = -1;
	while (src[++counter_src])
		dst[counter_src] = src[counter_src];
	dst[counter_src] = '\0';
	return (dst);
}
