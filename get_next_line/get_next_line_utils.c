#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
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
	while (str[i] != n || str[i] == '\0')
		i++;
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
	free(me);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*me;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	me = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!me)
		return (NULL);
	// free(me);
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
	unsigned char me;

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