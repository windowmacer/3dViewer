#include "headerCAD.h"

typedef struct s_gnl
{
	char			*stl;
	char			*str;
	int				f;
	ssize_t			gg;
}	t_gnl;

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*r;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strchr(const char *str, int ch)
{
	char	*s;
	char	c;

	if (!str)
		return (NULL);
	c = (char)ch;
	s = (char *)str;
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return (s);
}

char	*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	while (i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_freejoin(char	*s1, char	*s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strndup("", 0);
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

static char	*null_storage(char	**stl, int	*f, int x)
{
	char	*p;
	char	*s;

	*f = x;
	if (!*stl)
		return (ft_strndup("", 0));
	p = ft_strchr(*stl, '\n');
	if (!p)
	{
		s = *stl;
		return (s);
	}
	s = ft_strndup(*stl, ((p - *stl) + 1));
	if (!s)
		return (NULL);
	free(*stl);
	*stl = NULL;
	return (s);
}

static char	*storage(char	**stl)
{
	char	*p;
	char	*temp;
	char	*s;

	if (!*stl)
		return (ft_strndup("", 0));
	p = ft_strchr(*stl, '\n');
	if (!p)
	{
		s = *stl;
		return (s);
	}
	s = ft_strndup(*stl, ((p - *stl) + 1));
	if (!s)
		return (NULL);
	temp = ft_strndup(p + 1, strlen(p + 1));
	free(*stl);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	*stl = temp;
	return (s);
}

static int	check_line(char *stl)
{
	char	*p;

	p = ft_strchr(stl, '\n');
	if (stl && (ft_strchr(stl, '\n')) && (!(*(p++))))
		return (-1);
	if (stl && (ft_strchr(stl, '\n')) && ((*(p))))
		return (1);
	return (0);
}

char	*ft_gnl(int fd, t_gnl	*st, char	*buf)
{
	static char		*stl;
	static int		f;

	if (f > 0 && (check_line(stl) < 0))
		return (null_storage(&stl, &f, 1));
	else if (f > 0 && (check_line(stl) > 0))
		return (storage(&stl));
	while (st->gg)
	{
		st->gg = read(fd, buf, 1);
		if (!st->gg)
			break ;
		buf[st->gg] = '\0';
		f = 1;
		stl = ft_freejoin(stl, buf);
		if (ft_strchr(buf, '\n'))
			st->gg = 0;
		if (check_line(stl) < 0)
			return (null_storage(&stl, &f, 1));
		else if (check_line(stl) > 0)
			return (storage(&stl));
	}
	if ((f > 0))
		return (null_storage(&stl, &f, -1));
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_gnl			st;
	char			buf[2];

	if (read(fd, buf, 0) == -1)
		return (NULL);
	st.gg = 1;
	return (ft_gnl(fd, &st, buf));
}
