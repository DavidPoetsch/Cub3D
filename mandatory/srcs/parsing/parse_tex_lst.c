/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:59:38 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/30 12:04:13 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**get_paths(char *name, t_textures *textures)
{
	int			len;
	t_textures	*curr;

	if (!name || !textures)
		return (NULL);
	curr = textures;
	len = ft_strlen(name);
	while (curr)
	{
		if (ft_strncmp(name, curr->name, len) == CMP_OK
			&& curr->name[len] == '\0')
			return (curr->paths);
		curr = curr->next;
	}
	return (NULL);
}

int	append_to_texlst(t_textures **tex_lst, t_textures *new)
{
	t_textures	*curr;
	int			len;

	if (!*tex_lst)
		*tex_lst = new;
	else
	{
		curr = *tex_lst;
		len = ft_strlen(new->name);
		while (curr)
		{
			if (ft_strcmp(new->name, curr->name))
			{
				free_tex(&new);
				ft_eprintf("Error: texture (%s) already exists\n");
				return (ERROR);
			}
			if (!curr->next)
				break ;
			curr = curr->next;
		}
		curr->next = new;
	}
	return (SUCCESS);
}

static void	assign_mandatory(char **paths, t_textures **new)
{
	(*new)->name = ft_strdup(paths[0]);
	if (!(*new)->name)
	{
		free(new);
		*new = NULL;
		result_failed("ft_strdup", __func__, __FILE__);
		return ;
	}
	(*new)->tex_count = get_tex_count(paths) - 1;
	free(paths[0]);
	paths[0] = paths[(*new)->tex_count];
	paths[(*new)->tex_count] = NULL;
	(*new)->paths = paths;
	(*new)->next = NULL;
}

t_textures	*create_new_texlst(char **paths)
{
	t_textures	*new;

	if (!is_valid_texture(paths[0]))
	{
		ft_eprintf("Error: invalid texture (%s)\n", paths[0]);
		return (NULL);
	}
	new = ft_calloc(1, sizeof(t_textures));
	if (!new)
	{
		result_failed("ft_calloc", __func__, __FILE__);
		return (NULL);
	}
	assign_mandatory(paths, &new);
	return (new);
}
