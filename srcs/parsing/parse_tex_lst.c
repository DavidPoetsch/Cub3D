/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:59:38 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/18 15:36:25 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **get_paths(char *name, t_textures *textures)
{
	int len;
	t_textures *curr;

	if (!name || !textures)
		return (NULL);
	curr = textures;
	len = ft_strlen(name);
	while(curr)
	{
		if (ft_strncmp(name, curr->name, len) == CMP_OK && curr->name[len] == '\0')
			return (curr->paths);
		curr = curr->next;
	}
	return (NULL);
}

int	append_to_texlst(t_textures **tex_lst, t_textures *new)
{
	t_textures *curr;
	int len;
	
	if (!*tex_lst)
		*tex_lst = new;
	else
	{
		curr = *tex_lst;
		len = ft_strlen(new->name);
		while (curr && curr->next)
		{
			if (ft_strncmp(new->name, curr->name, len) == CMP_OK && curr->name[len] == '\0')
			{
				ft_eprintf("Error: texture (%s) already exists\n");
				free(new->name);
				ft_free_str_lst(&new->paths, true);
				return(ERROR);
			}
			curr = curr->next;
		}
		curr->next = new;
	}
	return (SUCCESS);
}

t_textures *create_new_texlst(char **paths)
{
	t_textures *new;

	new = ft_calloc(1 , sizeof(t_textures));
	if (!new)
	{
		result_failed("ft_calloc", __func__, __FILE__);
		return (NULL);
	}
	if (ft_strncmp(paths[0], "B_", 2) == CMP_OK && paths[0][2] != '\0')
	{
		new->name = ft_substr(paths[0], 2, 1);
		if (!new->name)
		{
			free(new);
			result_failed("ft_substr", __func__, __FILE__);
			return (NULL);
		}
		free(paths[0]);
	}
	else
		new->name = paths[0];
	new->paths = paths + 1;
	new->next = NULL;
	return (new);
}
