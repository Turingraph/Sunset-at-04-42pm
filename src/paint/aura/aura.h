#ifndef AURA_H
# define AURA_H

# include "../../utils/taylor/taylor.h"
# include "../../utils/libft/libft.h"
# include <fcntl.h>

// arithmetic.c

int		aura_root_xyz(const t_fdf_table *dst, size_t index);
int		aura_addsub(const t_fdf_table *dst, size_t index);

// fermat.c

int		aura_fermat(const t_fdf_table *dst, size_t index, size_t power);
int		aura_fermat2(const t_fdf_table *dst, size_t index);
int		aura_fermat3(const t_fdf_table *dst, size_t index);
int		aura_fermat4(const t_fdf_table *dst, size_t index);
int		aura_fermat5(const t_fdf_table *dst, size_t index);
int		aura_fermat6(const t_fdf_table *dst, size_t index);

// inequality.c

int		aura_triangle_inequality(const t_fdf_table *dst, size_t index);
int		aura_amgm_inequality(const t_fdf_table *dst, size_t index);
int		aura_cauchy_schwarz_inequality_3d(const t_fdf_table *dst, size_t index);

// maxtri.c

int		aura_maxcos(const t_fdf_table *dst, size_t index);
int		aura_maxecos(const t_fdf_table *dst, size_t index);
int		aura_maxsin(const t_fdf_table *dst, size_t index);
int		aura_maxesin(const t_fdf_table *dst, size_t index);
int		aura_maxexp(const t_fdf_table *dst, size_t index);

// metric.c

int		aura_pythagoras(const t_fdf_table *dst, size_t index);
int		aura_max_xyz(const t_fdf_table *dst, size_t index);
int		aura_min_xyz(const t_fdf_table *dst, size_t index);

// mintri.c

int		aura_mincos(const t_fdf_table *dst, size_t index);
int		aura_minecos(const t_fdf_table *dst, size_t index);
int		aura_minsin(const t_fdf_table *dst, size_t index);
int		aura_minesin(const t_fdf_table *dst, size_t index);
int		aura_minexp(const t_fdf_table *dst, size_t index);

// paint.c

int		aura_conway(const t_fdf_table *dst, size_t index, int threshold);
void	paint_aura_fdf_table(t_fdf_table *dst, t_fdf_channel channel,
			int (*aura)(const t_fdf_table *dst, size_t index));

#endif
