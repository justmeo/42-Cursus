#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i++;
	return (i);
}

char	*opp_strchr(char *str, int n)
{
	int		i;
	char	*me;
	char	*start;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != n)
	{
		if (str[i] == '\0')
			return (str);
		i++;
	}
	if (str[i] == n)
		i++;
	me = (char *)malloc((i + 1) * sizeof(char));
	if (!me)
		return (NULL);
	start = me;
	while (i > 0)
	{
		*me++ = *str++;
		i--;
	}
	*me = '\0';
	return (start);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*me;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	me = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) - 1) * sizeof(char));
	if (!me)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		me[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		me[i] = s2[j];
		i++;
		j++;
	}
	me[i] = '\0';
	return (me);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	me;

	me = c;
	while (*str)
	{
		if (*str == me)
			return ((char *)str);
		++str;
	}
	if (me == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*me;

	me = (char *)malloc((ft_strlen(str)) * sizeof(char));
	if (!me)
		return (NULL);
	if (me != NULL)
	{
		ft_memcpy(me, str, ft_strlen(str));
	}
	return (me);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*i;
	const char	*j;

	i = (char *)dst;
	j = (const char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*i++ = *j++;
	return (dst);
}
