#include <stdlib.h>
#include "worldObject.h"
#include "vec_math.h"

pointCloud_t* newPointCloud(int pcount){
    vec3_t* newPoints = malloc(sizeof(vec3_t) * pcount);
    pointCloud_t* new = malloc(sizeof(pointCloud_t *));

    new->count = pcount;
    new->points = newPoints;

    return new;
}