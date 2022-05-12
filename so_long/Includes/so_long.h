#ifndef SO_LONG_H
# define SO_LONG_H

# define TILES 50
# define PATH_W "./Assets/wall.xpm"
# define PATH_E "./Assets/empty.xpm"
# define PATH_EX "./Assets/exit.xpm"
# define PATH_PD "./Assets/player_down.xpm"
# define PATH_PT "./Assets/player_top.xpm"
# define PATH_PR "./Assets/player_right.xpm"
# define PATH_PL "./Assets/player_left.xpm"
# define PATH_I "./Assets/item.xpm"
# define PATH_V "./Assets/venom.xpm"
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <libft.h>

# define BUFFER_SIZE 1

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**map;
	int			enemy_win;
	int			end_game;
	int			steps;
	int			player_side;
	int			player_x;
	int			player_y;
	int			player_bup_x;
	int			player_bup_y;
	int			valid;
	int			end_col;
	int			colum;
	int			line;
	int			check_player;
	int			check_exit;
	int			check_collect;
	int			item_bup;
	
}				t_vars;

typedef struct s_img
{
	t_asset	*wall;
	t_asset	*emp;
	t_asset	*exit;
	t_asset	*player_down;
	t_asset	*player_up;
	t_asset	*player_left;
	t_asset	*player_right;
	t_asset	*item;
	t_asset	*enemy;
}				t_img;

typedef struct s_asset
{
	void	*img;
	char	*pixel;
	int		pos_x;
	int		pos_y;
	int		bpp;
	int		line_size;
	int		endian;
}				t_asset;

#endif
