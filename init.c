
#include "structs.h"

void	init_struct(t_img *img)
{
	img->floor = malloc(3 * sizeof(int));
	if (!img->floor)
		return (NULL);
	
}
