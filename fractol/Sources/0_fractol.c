#include "../Includes/fractol.h"

void	ft_check_arg(int argc, char ***argv)
{
	argc--;
	printf("%s", *argv[argc]);
	while (argc > 0)
	{
		if (ft_strncmp(*argv[argc], "1", 1) == 0)
			argc--;
		else if (ft_strncmp(*argv[argc], "2", 1) == 0)
			argc--;
		else
		{
			*argv = NULL;
			return ;
		}
	}
	*argv[0] = ft_itoa(argc - 1);
	return ;
}
	
int	main(int argc, char **argv)
{
	printf("%s", argv[argc - 1]);
	if (argc > 1)
		ft_check_arg(argc, &argv);
	if (argv)
		ft_putstr("ok");
		//ft_launch_minilibx(argv);
	ft_print_list_arg_valid();
	return (0);
}

void	ft_print_list_arg_valid(void)
{
	ft_putstr("Usage: ./Fract-ol <fractal>.....\n");
	ft_putstr("valid fractals :\n\t- Julia => 1\n\t- Mandelbrot => 2");
}
