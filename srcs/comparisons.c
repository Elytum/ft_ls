#include "../includes/ft_ls.h"

int			ft_cmpname(t_file *s1, t_file *s2)
{
	return (ft_strcmp(s1->name, s2->name));
}

int			ft_cmprname(t_file *s1, t_file *s2)
{
	return (ft_strcmp(s2->name, s1->name));
}

int			ft_cmpdate(t_file *s1, t_file *s2)
{
	int		ret;

	ret = s2->filestat.st_mtime - s1->filestat.st_mtime;
	if (!ret)
		ret = ft_strcmp(s1->name, s2->name);
	return (ret);
}

int			ft_cmprdate(t_file *s1, t_file *s2)
{
	int		ret;

	ret = s1->filestat.st_mtime - s2->filestat.st_mtime;
	if (!ret)
		ret = ft_strcmp(s2->name, s1->name);
	return (ret);
}

compare		ft_get_function(char flags)
{
	if (!(flags & LR_FLAG) && !(flags & LT_FLAG))
		return (&ft_cmpname);
	if (!(flags & LT_FLAG))
		return (&ft_cmprname);
	if (!(flags & LR_FLAG))
		return (&ft_cmpdate);
	return (&ft_cmprdate);
}
