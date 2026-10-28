#include "spots.h"


/*

// This is the incorrect implementation of Conway game.
// I comment it because it is out of the scope of the first version.

// time : O(n)
// space: O(1)
static size_t	get_rule_length(const char *str, size_t maxx)
{
	size_t	i;

	i = 0;
	while (str != NULL && *str != '\0' && i < maxx)
	{
		i += 1;
		str += 1;
	}
	return (i);
}

static bool	conway_fdf_table_unit(t_fdf_table *dst, const char *rules, size_t index, size_t rules_length)
{
	size_t	counts;

	counts = (size_t)f_abs_int(dst->arr[index]);
	if (counts >= rules_length)
		return (false);
	if (rules[counts] % 2 == 0)
		return (false);
	return (true);
}

void	conway_fdf_table(t_fdf_table *dst, const char *rules)
{
	size_t	i;
	size_t	rules_length;

	if (dst == NULL || dst->arr == NULL || mul_overflow_size_t(dst->col, dst->row) == false
		|| rules == NULL || *rules == '\0')
		return ;
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (dst->arr[i] > 0)
			dst->arr[i] = (int)count_neighbor_fdf_table(dst, i) + 1;
		else
			dst->arr[i] = ((int)count_neighbor_fdf_table(dst, i) + 1) * -1;
		i += 1;
	}
	rules_length = get_rule_length(rules, 8);
	i = 0;
	while (i < dst->row * dst->col)
	{
		if (conway_fdf_table_unit(dst, rules, i, rules_length) == true)
			dst->arr[i] = 1;
		else
			dst->arr[i] = 0;
		i += 1;
	}
}
*/
