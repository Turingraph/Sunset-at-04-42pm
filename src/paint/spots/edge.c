#include "spots.h"

bool	is_available_left(size_t col, size_t row, size_t index)
{
	if (mul_overflow_size_t(col, row) == false)
		return (false);
	if (index % col == 0)
		return (false);
	return (true);
}

bool	is_available_right(size_t col, size_t row, size_t index)
{
	if (mul_overflow_size_t(col, row) == false)
		return (false);
	if (index % col == col - 1)
		return (false);
	return (true);
}

bool	is_available_up(size_t col, size_t row, size_t index)
{
	if (mul_overflow_size_t(col, row) == false)
		return (false);
	if (index / col == 0)
		return (false);
	return (true);
}

bool	is_available_down(size_t col, size_t row, size_t index)
{
	if (mul_overflow_size_t(col, row) == false)
		return (false);
	if (index / col == row - 1)
		return (false);
	return (true);
}

bool	is_edge_frame(size_t col, size_t row, size_t index)
{
	if (mul_overflow_size_t(col, row) == false)
		return (false);
	if (is_available_up(col, row, index) == false
		|| is_available_down(col, row, index) == false
		|| is_available_left(col, row, index) == false
		|| is_available_right(col, row, index) == false)
		return (true);
	return (false);
}
