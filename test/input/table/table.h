#ifndef TABLE_TESTER_H
# define TABLE_TESTER_H

# include "../../../src/input/table/table.h"
#include "../../../src/utils/debug/debug.h"

typedef struct t_scale_dim_tester t_scale_dim_tester;

struct t_scale_dim_tester
{
	const char		*file_name;
	const int		*arr;
	size_t			row;
	size_t			col;
	size_t			scale_row;
	size_t			scale_col;
};

#endif
