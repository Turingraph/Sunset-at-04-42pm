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
			.row = 3, .col = 5, .length = 0, .file_name = "10-70.fdf", .points = (t_3d_point []){
				{.x = 0.0, .y = 0.0, .z = 0.0}, {.x = 0.0, .y = 0.0, .z = 0.0}
			}
		},
		{
			.row = 11, .col = 15, .length = 0, .file_name = "20-60.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 4, .col = 6, .length = 0, .file_name = "42.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 45, .col = 6, .length = 0, .file_name = "50-4.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 45, .col = 4, .length = 0, .file_name = "100-6.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 4, .col = 8, .length = 0, .file_name = "basictest.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 0, .col = 0, .length = 0, .file_name = "ee", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 4, .col = 4, .length = 0, .file_name = "elem-col.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 36, .col = 8, .length = 0, .file_name = "elem-col.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 2, .col = 2, .length = 0, .file_name = "elem.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 15, .col = 12, .length = 0, .file_name = "elem2.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
			}
		},
		{
			.row = 7, .col = 7, .length = 0, .file_name = "pentenegpos.fdf", .points = (t_3d_point []){
				{.x = 0, .y = 0, .z = 0}, {.x = 0, .y = 0, .z = 0}
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
			score += 1;
		else
		{
			write(1, testers[i].file_name, f_strlen(testers[i].file_name));
			write(1, "\n", 1);
		}
		free_triangle_arr(&output, 0);
		free_table_fdf(&table);
		i += 1;
	}
	write_total_score(score, max_score);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic/triangle_pair/fdf_edge_ux00.out
*/