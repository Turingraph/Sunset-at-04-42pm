#include "taylor.h"

// time : O(n)
// space: O(1)
double	test_identity(double x)
{
	return (f_root_finding(x, 1));
}

// time : O(n)
// space: O(1)
double	test_sqrt(double x)
{
	return (f_root_finding(x, 2));
}

// time : O(n)
// space: O(1)
double	test_cubrt(double x)
{
	return (f_root_finding(x, 3));
}

// time : O(n)
// space: O(1)
double	test_cube(double x)
{
	return (f_pow(x, 3));
}

// time : O(n)
// space: O(1)
double	test_normal(double x)
{
	return (normal_distribution(1, 2, x));
}

// time : O(n)
// space: O(1)
bool	math_tester(size_t max_score, const double **arr,
	double (*math_func)(double x))
{
	size_t	i;
	size_t	score;
	double	err;

	score = 0;
	i = 0;
	while (i < max_score)
	{
		err = f_abs(math_func(arr[i][0]) - arr[i][1]);
		if (err < 0.01)
			score += 1;
		else
		{
			ft_putnbr_fd(i, 1, "0123456789", 1);
			write(1, ", ", 2);
		}
		i += 1;
	}
	write(1, "\n", 1);
	write_score(score, max_score);
	if (score == max_score)
		return (true);
	return (false);
}

int	main(void)
{
	size_t	score;
	double	*arr_identity_tester[] = {
		(double []){112. , 112. },
		(double []){23.  , 23.  },
		(double []){0.665, 0.665},
		(double []){6.650, 6.650}
	};
	double	*arr_sin_tester[] = {
		(double []){112. , -0.889995604367},
		(double []){23.  , -0.846220404175},
		(double []){0.665, 0.617059132728},
		(double []){6.650, 0.358643853493}
	};
	double	*arr_cos_tester[] = {
		(double []){112. , 0.455969104444},
		(double []){23.  ,-0.532833020333},
		(double []){0.665, 0.786916785128},
		(double []){6.650, 0.933474470113}
	};
	double	*arr_sqrt_tester[] = {
		(double []){836747233.0, 28926.5835003},
		(double []){8367472.0, 2892.65829299},
		(double []){112. , 10.5830052443},
		(double []){23.  , 4.79583152331},
		(double []){0.665, 0.815475321515},
		(double []){6.650, 2.57875939165}
	};
	double	*arr_cubrt_tester[] = {
		(double []){2.   , 1.25992104989},
		(double []){112. , 4.82028452835},
		(double []){23.  , 2.84386697985},
		(double []){0.665, 0.872851873519},
		(double []){0.665, 0.872851873519},
		(double []){6.650, 1.88050235557}
	};
	double	*arr_cube_tester[] = {
		(double []){112. , 1404928.0},
		(double []){23.  , 12167.0},
		(double []){0.665, 0.294079625},
		(double []){6.650, 294.079625}
	};
	double	*arr_normal_tester[] = {
		(double []){1.12  , 0.270863971798},
		(double []){2.3   , 0.381387815461},
		(double []){0.665 , 0.163645785221},
		(double []){6.650 , 0.00000804718245649}
	};
	double	*arr_exp_tester[] = {
		(double []){1.12  , 3.06485420329},
		(double []){2.3   , 9.97418245481},
		(double []){0.665 , 1.94449052134},
		(double []){6.650 , 772.784325535}
	};

	score = 0;
	write(1, "identity: ", 11);
	if (math_tester(4, (const double **)arr_identity_tester, test_identity) == true)
		score += 1;
	write(1, "sqrt: ", 6);
	if (math_tester(6, (const double **)arr_sqrt_tester, test_sqrt) == true)
		score += 1;
	write(1, "sin: ", 5);
	if (math_tester(4, (const double **)arr_sin_tester, f_sin) == true)
		score += 1;
	write(1, "cos: ", 5);
	if (math_tester(4, (const double **)arr_cos_tester, f_cos) == true)
		score += 1;
	write(1, "exp: ", 5);
	if (math_tester(4, (const double **)arr_exp_tester, f_exp) == true)
		score += 1;
	write(1, "cubrt: ", 7);
	if (math_tester(6, (const double **)arr_cubrt_tester, test_cubrt) == true)
		score += 1;
	write(1, "cube: ", 6);
	if (math_tester(4, (const double **)arr_cube_tester, test_cube) == true)
		score += 1;
	write(1, "normal: ", 8);
	if (math_tester(4, (const double **)arr_normal_tester, test_normal) == true)
		score += 1;
	if (score == 8)
		write(1, "The utils/math/ module works correctly.\n", 41);
	else
		write(1, "The utils/math/ module have issue.\n", 36);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/utils/taylor/test.out
*/
