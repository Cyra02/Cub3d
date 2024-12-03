/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:22:08 by ciestrad          #+#    #+#             */
/*   Updated: 2024/12/03 11:47:10 by ciestrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*no;
	char	*we;
	char	*so;
	char	*ea;
	int		f;
	int		c;
}		t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

//----errors----
int		ft_error(int code);


//----ft_parseo----
int		check_input(t_map *map, char *line);
void	set_map(t_map *map);
int		set_map_size(char *file, int *size);


//----utils_parse----
int		set_only(char *line, char *set);
int		is_set(char c, char *set);
size_t	count_arrays(char **array);
size_t	free_array(char **array);
void	free_map(t_map *map);


//----utils_parse02----
int		ft_color(char *line);

//----parse_struct----
int		read_file(t_map *map, char *file, int size);
int		check_element(t_map *map, char *line);
int		get_element(t_map *map, char *line);
int		get_map(int fd, t_map *map, char *file, int size);


//----gent_next_line----
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_read(int fd, char *save);
char	*get_line(char *buffer);
void	remake_save(char *save);
char	*get_next_line(int fd, char **out, int clear);

#endif