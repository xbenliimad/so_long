#include "so_long.h"

void    ft_error(char *message)
{
    ft_printf("%s\n", message);
    exit(1);
}

int	ft_custom_strlen(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_custom_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_custom_strlen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = ft_custom_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}

char	*ft_custom_strjoin(char **s1, char *s2)
{
	int		t_len;
	char	*str;

	if (!s2)
		return (NULL);
	t_len = ft_custom_strlen(*s1) + ft_custom_strlen(s2);
	str = (char *)ft_calloc(t_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_custom_strlcat(str, *s1, ft_custom_strlen(*s1) + 1);
	ft_custom_strlcat(str, s2, t_len + 1);
	free(*s1);
	return (str);
}