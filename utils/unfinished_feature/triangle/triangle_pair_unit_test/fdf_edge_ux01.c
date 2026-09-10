#include"triangle_pair.h"

int	main(void)
{
	size_t				score;
	size_t				i;
	size_t				max_score = 12;
	t_table_fdf			table;
	t_triangle_arr		output;
	size_t				index;
	e_edge				edge_mode = EDGE_X;
	t_triangle_tester	testers[] = {
		{
			.row = 1, .col = 1, .length = 0, .file_name = "10-70.fdf", .points = (t_3d_point []){
				{.x = 1.0, .y = 1.0, .z = 4.0}, {.x = 2.0, .y = 1.0, .z = 90.0}
			}
		},
		{
			.row = 5, .col = 15, .length = 0, .file_name = "20-60.fdf", .points = (t_3d_point []){
				{.x = 12.0, .y = 5.0, .z = 105.0}, {.x = 13.0, .y = 5.0, .z = 57.0}
			}
		},
		{
			.row = 6, .col = 11, .length = 0, .file_name = "42.fdf", .points = (t_3d_point []){
				{.x = 11.0, .y = 6.0, .z = 10}, {.x = 12.0, .y = 6.0, .z = 10}
			}
		},
		{
			.row = 27, .col = 4, .length = 0, .file_name = "50-4.fdf", .points = (t_3d_point []){
				{.x = 4.0, .y = 27.0, .z = 5.0}, {.x = 5.0, .y = 27.0, .z = 2.0}
			}
		},
		{
			.row = 74, .col = 7, .length = 0, .file_name = "100-6.fdf", .points = (t_3d_point []){
				{.x = 7.0, .y = 74.0, .z = 2.0}, {.x = 8.0, .y = 74.0, .z = 2.0}
			}
		},
		{
			.row = 6, .col = 8, .length = 0, .file_name = "basictest.fdf", .points = (t_3d_point []){
				{.x = 8.0, .y = 6.0, .z = 1.0}, {.x = 9.0, .y = 6.0, .z = 2.0}
			}
		},
		{
			.row = 10, .col = 20, .length = 0, .file_name = "ee", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 4, .col = 4, .length = 0, .file_name = "elem-col.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 7, .col = 7, .length = 0, .file_name = "elem-col.fdf", .points = (t_3d_point []){
				{.x = 7.0, .y = 7.0, .z = 2.0}, {.x = 8.0, .y = 7.0, .z = 5.0}
			}
		},
		{
			.row = 1, .col = 1, .length = 0, .file_name = "elem.fdf", .points = (t_3d_point []){
				{.x = 1.0, .y = 1.0, .z = 10.0}, {.x = 2.0, .y = 1.0, .z = 10.0}
			}
		},
		{
			.row = 9, .col = 4, .length = 0, .file_name = "elem2.fdf", .points = (t_3d_point []){
				{.x = 4.0, .y = 9.0, .z = 50.0}, {.x = 5.0, .y = 9.0, .z = 50.0}
			}
		},
		{
			.row = 8, .col = 19, .length = 2, .file_name = "pentenegpos.fdf", .points = (t_3d_point []){
				{.x = 19.0, .y = 8.0, .z = 19.0}, {.x = 20.0, .y = 8.0, .z = 20.0}
			}
		},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		table = open_table_fdf_file(testers[i].file_name, "input_examples/fdf_positive/", parse_fdf_line_rgba, false);
		index = testers[i].row * table.col + testers[i].col;
		output = f_fdf_edge((const t_table_fdf *)&table, index, edge_mode, false);
		if (compare_3dpoint_edge_tester(&output, &testers[i]) == true)
			// && (testers[i].length == 0 || (testers[i].length == 2
				// && true == compare_table_edge_3d_arr(&table, &output, index, edge_mode))))
			score += 1;
		else
		{
			write(1, testers[i].file_name, f_strlen(testers[i].file_name));
			write(1, "\n", 1);
			write_triangle_pair_graphic(&table, index);
			write_triangle_arr(1, &output);
			write(1, "\n---------------------------------------\n", 42);
		}
		free_triangle_arr(&output, 0);
		free_table_fdf(&table);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic/triangle_pair/fdf_edge_vx01.out
*/