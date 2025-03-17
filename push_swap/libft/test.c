#include "libft.h"

int	main(int argc, char *argv[])
{
	int result;
	int result2;
	int i = 0;
	int o = 1;
	ft_printf("%s\n", argv[1]);
	while(argv[o])
	{
		if (ft_isdigit(argv[o][i]) == 0)
		{
			result = ft_atoi(argv[1]);
			result2 = atoi(argv[1]);
			ft_printf("%i\n", result);
			ft_printf("%i\n", result2);
			i ++;
		}
		else
			ft_printf("error\n");
		o ++;
		break;
	}
	//if (ft_isdigit(argv[2][0]))
	//{
	//	ft_printf("%s\n", argv[2]);
	//	result = ft_atoi(argv[2]);
	//	result2 = atoi(argv[2]);
	//	ft_printf("%i\n", result);
	//	ft_printf("%i\n", result2);
	//}
	return (0);
}

//int	ft_isdigit_test(int c)
//{
//	if (c >= '0' && c <= '9')
//	{
//		ft_printf("%c", c);
//		return (1);
//	}
//	ft_printf("%c", c);
//	return (0);
//}