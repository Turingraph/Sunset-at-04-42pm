#ifndef GET_NEXT_LINE_TESTER_H
# define GET_NEXT_LINE_TESTER_H

#include "../../../src/input/get_next_line/get_next_line.h"
#include "../../../src/debug/debug/debug.h"

// https://github.com/Tripouille/gnlTester/tree/master/files

typedef struct t_gnl_tester t_gnl_tester;

struct t_gnl_tester
{
	const char	*file_name;
	const char	**arr;
	size_t		total_lines;
	bool		read_entire_file;
};

typedef struct t_file_tester t_file_tester;

struct t_file_tester
{
	const char	*file_name;
	size_t		total_lines;
};

#endif
