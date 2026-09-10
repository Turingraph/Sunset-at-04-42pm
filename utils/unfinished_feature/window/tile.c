#include"window.h"

// floor(1080 / 2^5) = 33
// floor(1920 / 2^5) = 60
// time : O(n, where n = resolution <= 10, because 2^10 = 1024)
// space: O(1)
size_t	init_tile_size(size_t side_length, size_t resolution)
{
	return (side_length / (size_t)f_pow(2.0, resolution));
}

// f(1080, 5, 1080) = floor(1080 / g(1080, 5)) = 32
// f(1920, 5, 1080) = floor(1920 / g(1080, 5)) = 58
// time : O(1)
// space: O(1)
size_t	init_alltiles_count(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	if (init_tile_size(fixed_length, resolution) == 0)
		return (0);
	return (side_length / init_tile_size(fixed_length, resolution));
}

/*
I have grapheme color synesthesia, and I have one funny story
which is when I coding computer graphic,
I thought at first glance that 1056 is larger than 1080
because 80 is light blue but 5 is orange yellow and 6 is dark purple blue,
then I realize that this is non sense
and I just confuse the color of the letter with its semantic meaning.

P.S. I very rarely confused by my own synesthesia like this,
but this is one very rare exception.
*/

// f(1080, 5, 1080) = init_tile_size(1080, 5) * init_tile_count(1080, 5, 1080)
//			= 1056
// f(1920, 5, 1080) = init_tile_size(1080, 5) * init_tile_count(1920, 5, 1080)
//			= 58 * 33 = 1914
// time : O(1)
// space: O(1)
size_t	init_alltiles_size(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	size_t	output;

	output = init_alltiles_count(side_length,
			resolution, fixed_length);
	return (output * init_tile_size(fixed_length, resolution));
}

// f(1080, 5, 1080) = (1080 - 1056) / 2 = 12
// f(1920, 5, 1080) = (1920 - 1914) / 2 = 3
// time : O(1)
// space: O(1)
int	init_alltiles_offset(size_t side_length,
	size_t resolution, size_t fixed_length)
{
	int	output;

	output = init_alltiles_size(side_length, resolution, fixed_length);
	return ((side_length - output) / 2);
}
