#include"window.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 100;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}


int	main(int len, char **str)
{
	t_table_fdf	table;
	t_fdf		output;
	t_background bc = {.color = f_rgba_to_int32(255, 255, 255, 255), .first_post = NULL, .tiles_resolution = 1};
	t_ink32	style = {.color = f_rgba_to_int32(224, 84, 84, 255), .thickness = 1, .type = E_PIXEL_ART};

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	scale_multiplication_fdf(&table, 10, HEIGHT);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	output = init_fdf(&table);
	view_master_piece(&output, NULL, style, bc);
	free_fdf(&output);
	return (0);
}


/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/window/ascii_fdf.out input_examples/view/lerem_ipsum_nvscript.txt

<-leak-kinds=all ./coding_examples/out/graphic/window/ascii_fdf.out input_examples/view/lerem_ipsum_nvscript.txt                                 
==354954== Memcheck, a memory error detector
==354954== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==354954== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==354954== Command: ./coding_examples/out/graphic/window/ascii_fdf.out input_examples/view/lerem_ipsum_nvscript.txt
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F875: draw_fdf_mlx_y_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FBF7: draw_fdf_mlx_y (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD21: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F8D3: draw_fdf_mlx_y_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FBF7: draw_fdf_mlx_y (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD21: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F92D: draw_fdf_mlx_y_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FBF7: draw_fdf_mlx_y (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD21: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F52A: draw_fdf_mlx_x_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FA92: draw_fdf_mlx_x (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD35: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F588: draw_fdf_mlx_x_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FA92: draw_fdf_mlx_x (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD35: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 
==354954== Conditional jump or move depends on uninitialised value(s)
==354954==    at 0x10F5E2: draw_fdf_mlx_x_unit (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10FA92: draw_fdf_mlx_x (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10AD35: view_master_piece (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954==    by 0x10A6C5: main (in /home/pc/Desktop/GrASCIIfi/coding_examples/out/graphic/window/ascii_fdf.out)
==354954== 

*/