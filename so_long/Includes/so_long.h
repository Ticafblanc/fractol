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
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <libft.h>

// define /

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**map;
	int			error_map;
	int			wall_x;
	int			wall_y;
	int			player_x;
	int			player_y;
	int			player_side;
	int			item;
	int			enemy_win;
	int			end_game;
	int			steps;
}				t_vars;

	//0_main.c
t_vars	*init_t_vars(void);
int		update(t_vars *vars);
int		read_key(int keycode, t_vars *vars);
int		close_game(t_vars *vars);

	//1-0_check.c
int		check_map(char *argv, t_vars *vars);
int		read_arg(char *argv, t_vars *vars);
int		check_wall_down(t_vars *vars);
int		check_wall_side(t_vars *vars);
int		check_wall_up(t_vars *vars);

	//1-1_check.c
int		check_cara(t_vars *vars, int x, int y);
int		check_caractere(t_vars *vars);

	//2-0_init.c
int		init_game(t_vars *vars);
void	init_t_img(t_vars *vars);
void	init_window(t_vars *vars);

	//2-1_init_t_img.c
void	init_player(t_vars *vars);
void	init_enemy(t_vars *vars);
void	init_exit(t_vars *vars);
void	init_item(t_vars *vars);
void	init_wall(t_vars *vars);

	//4_put.c
void	put_game(t_vars *vars);
void	*read_map(t_vars *vars, int y, int x);

	//5_move.c
void	check_move(t_vars *vars, int y, int x);
void	check_side(t_vars *vars, int keycode);

	//6_utils.c
int		put_error_arg(int error);
void	free_map(t_vars *vars);

#endif
