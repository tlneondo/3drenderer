#include "worldObject.h"
#include "vec_math.h"

pointCloud_t* newPointCloud(int count){
    vec3_t* newPoints = malloc(sizeof(vec3_t) * count);
    pointCloud_t* new = {count, newPoints};

    return new;
}