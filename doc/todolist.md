
to do next
1.	fix paint/convolve/
	1.	float *kernel_ --> t_matrix kernel
	2.	convolve_fdf_table(t_fdf_table, float, size_t, bool) --> convolve_fdf_table(t_fdf_table, t_matrix) // Should you eliminate bool or not ?
2.	fix visualize/proj2d/
	1.	scale_fdf_proj2d(t_fdf_proj2d, float, float)
	2.	making proj2d_ more accurate
3.	test fib
