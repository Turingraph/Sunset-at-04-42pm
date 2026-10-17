#include "taylor.h"

// time : O(n)
// space: O(1)
float	test_identity(float x)
{
	return (f_root_finding(x, 1));
}

// time : O(n)
// space: O(1)
float	test_sqrt(float x)
{
	return (f_root_finding(x, 2));
}

// time : O(n)
// space: O(1)
float	test_cubrt(float x)
{
	return (f_root_finding(x, 3));
}

// time : O(n)
// space: O(1)
float	test_cube(float x)
{
	return (f_pow(x, 3));
}

// time : O(n)
// space: O(1)
float	test_normal(float x)
{
	return (normal_distribution(1, 2, x));
}

// time : O(n)
// space: O(1)
bool	math_tester(size_t max_score, const float **arr,
	float (*math_func)(float x))
{
	size_t	i;
	size_t	score;
	float	err;

	score = 0;
	i = 0;
	while (i < max_score)
	{
		err = f_abs(math_func(arr[i][0]) - arr[i][1]);
		if (err < 0.001)
			score += 1;
		i += 1;
	}
	write_total_score(score, max_score);
	if (score == max_score)
		return (true);
	return (false);
}

int	main(void)
{
	size_t	score;
	float	*arr_identity_tester[] = {
		(float []){112. , 112. },
		(float []){23.  , 23.  },
		(float []){0.665, 0.665},
		(float []){6.650, 6.650}
	};
	float	*arr_sin_tester[] = {
		(float []){112. , -0.889995604367},
		(float []){23.  , -0.846220404175},
		(float []){0.665, 0.617059132728},
		(float []){6.650, 0.358643853493}
	};
	float	*arr_cos_tester[] = {
		(float []){112. , 0.455969104444},
		(float []){23.  ,-0.532833020333},
		(float []){0.665, 0.786916785128},
		(float []){6.650, 0.933474470113}
	};
	float	*arr_sqrt_tester[] = {
		(float []){836747233.0, 28926.5835003},
		(float []){8367472.0, 2892.65829299},
		(float []){112. , 10.5830052443},
		(float []){23.  , 4.79583152331},
		(float []){0.665, 0.815475321515},
		(float []){6.650, 2.57875939165}
	};
	float	*arr_cubrt_tester[] = {
		(float []){2.   , 1.25992104989},
		(float []){112. , 4.82028452835},
		(float []){23.  , 2.84386697985},
		(float []){0.665, 0.872851873519},
		(float []){0.665, 0.872851873519},
		(float []){6.650, 1.88050235557}
	};
	float	*arr_cube_tester[] = {
		(float []){112. , 1404928.0},
		(float []){23.  , 12167.0},
		(float []){0.665, 0.294079625},
		(float []){6.650, 294.079625}
	};
	float	*arr_normal_tester[] = {
		(float []){1.12  , 0.270863971798},
		(float []){2.3   , 0.381387815461},
		(float []){0.665 , 0.163645785221},
		(float []){6.650 , 0.00000804718245649}
	};
	float	*arr_exp_tester[] = {
		(float []){1.12  , 3.06485420329},
		(float []){2.3   , 9.97418245481},
		(float []){0.665 , 1.94449052134},
		(float []){6.650 , 772.784325535}
	};

	score = 0;
	if (math_tester(4, (const float **)arr_identity_tester, test_identity) == true)
		score += 1;
	if (math_tester(6, (const float **)arr_sqrt_tester, test_sqrt) == true)
		score += 1;
	if (math_tester(4, (const float **)arr_sin_tester, f_sin) == true)
		score += 1;
	if (math_tester(4, (const float **)arr_cos_tester, f_cos) == true)
		score += 1;
	if (math_tester(4, (const float **)arr_exp_tester, f_exp) == true)
		score += 1;
	if (math_tester(6, (const float **)arr_cubrt_tester, test_cubrt) == true)
		score += 1;
	if (math_tester(4, (const float **)arr_cube_tester, test_cube) == true)
		score += 1;
	if (math_tester(4, (const float **)arr_normal_tester, test_normal) == true)
		score += 1;
	if (score == 8)
		write(1, "The utils/math/ module works correctly.\n", 41);
	else
		write(1, "The utils/math/ module have issue.\n", 36);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./test/out/utils/taylor/test.out
*/
