#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float *list;
    int dimension;
}Vector;

Vector* vector_sum(Vector v1 , Vector v2){
    if (v1.dimension!=v2.dimension){
        return NULL;
    }

    Vector v3;
    v3.dimension = v1.dimension;
    v3.list = (float*)malloc(v1.dimension*sizeof(float));
    for(int i=0;i<v1.dimension;i++){
        v3.list[i] = v1.list[i]+v2.list[i];
    }
    
    return &v3;

}

Vector* cross_product(Vector v1 , Vector v2){
    if (v1.dimension!=v2.dimension || v1.dimension!=3){
        return NULL;
    }
    
    Vector v3;
    v3.dimension = v1.dimension;
    v3.list = (float*)malloc(v1.dimension*sizeof(float));
    v3.list[0] = v1.list[1]*v2.list[2] - v1.list[2]*v2.list[1];
    v3.list[1] = v1.list[2]*v2.list[0] - v1.list[0]*v2.list[2];
    v3.list[2] = v1.list[0]*v2.list[1] - v1.list[1]*v2.list[0];

    return &v3; 
}
