#pragma once

#include "vec_math.h"


typedef struct{
    int count;
    vec3_t* points;
}  pointCloud_t;

pointCloud_t* newPointCloud(int count);


typedef struct{
    vec3_t rotation;
    vec3_t position;
} thing_t;

typedef struct{
    vec3_t rotation;
    vec3_t position;
    float fov;
} camera_t;
\