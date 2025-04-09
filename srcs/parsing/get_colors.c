/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstefane <lstefane@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:53:41 by lstefane          #+#    #+#             */
/*   Updated: 2025/04/09 12:35:20 by lstefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool is_valid_input(char *line)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] == ',')
			count++;
		if (count > 2)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_only_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] != '\n' && !ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int check_valid_color(char *str, int *color)
{
	int	value;

	if (is_only_digits(str))
	{
		value = ft_atoi(str);
		if (value < 0 || value > 256)
		{
			ft_eprintf("error: color value (%s) out of bounds\n", str);
			return (ERROR);
		}
		*color = value;
		return (SUCCESS);
	}
	ft_eprintf("error: invalid color value (%s)\n", str);
	return (ERROR);
}

int get_color(char *line, t_color *color)
{
	char **split;
	int res;

	res = SUCCESS;
	if (!is_valid_input(line))
		return result_error("invalid color input");
	split = ft_split(line, ',');
	if (!split)
		return result_failed("ft_split", __func__, __FILE__);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		ft_free_str_lst(&split, true);
		return result_error("invalid color input");
	}
	res = check_valid_color(split[0], &color->r);
	if (res == SUCCESS)
		res = check_valid_color(split[1], &color->g);
	if (res == SUCCESS)
		res = check_valid_color(split[2], &color->b);
	if (res == SUCCESS)
		color->col = (color->r << 16) | (color->g << 8) | color->b;
	ft_free_str_lst(&split, true);
	return (res);
}

int assign_color(char identifier, t_color **color, char **split)
{
	if (split[0][0] == identifier && split[0][1] == '\0')
	{
		if (*color)
		{
			ft_eprintf("Error: color (%s) already exists\n", split[0]);
			return (ERROR);
		}
		else
		{
			*color = ft_calloc(1, sizeof(t_color));
			if (!*color)
				return result_failed("color_exists", __func__, __FILE__);
			return (get_color(split[1], *color));
		}
	}
	return (ERROR);
}

// F 220,100,0