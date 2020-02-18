/**
 
    This is a series of helpers functions for use within VEX.
    These are all fairly comon functions but grabbed from a variety of areas on the interwebs.
 */


// returns the magnitude for a vector
vector setMag(vector vec; float max){
    vec = normalize(vec);
    vec *= max;
    return vec;
}

// returns the magnitude of a vector squared.
float magSq(vector vec){
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

// constrains a vector to not be above a certain value.
vector limit(vector vec; float max){
    float mSq = magSq(vec);
    if(mSq > max * max){
        vec /= sqrt(mSq);
        vec *= max;
    }
    
    return vec;
}

/**
    Generates a random float value between a min and a max.
    Pass in a seed value + min and max.
 */
float randFloat(float seed; int min; int max){
    return fit(rand(seed),0,1,min,max);
}

// rotate a matrix along the x axis at a certain angle.
matrix3 rotateX(matrix3 mat; float angle){
    vector axis = {1,0,0};
    return rotate(mat, angle, axis);
}

// rotate a matrix along the y axis at a certain angle.
matrix3 rotateY(matrix3 mat; float angle){
    vector axis = {0,1,0};
    return rotate(mat, angle, axis);
}

// rotates a matrix along the z axis at a certain angle.
matrix3 rotateZ(matrix3 mat; float angle){
    vector axis = {0,0,1};
    return rotate(mat, angle, axis);
}

/**
    Does a random rotation using matrices.
    Pass in a min and a max to use for the seedingi value.
 */
matrix3 randomRotation(int min;int max){
    vector axisX = {1,0,0};
    vector axisY = {0,1,0};
    vector axisZ = {0,0,1};
    
    matrix3 xMat = ident();
    matrix3 yMat = ident();
    matrix3 zMat = ident();
    
    float angle = randFloat(3.14 * i,min,max);
    rotate(xMat,angle,axisX);
    rotate(yMat,angle,axisY);
    rotate(zMat,angle,axisZ);
    
    return xMat * yMat * zMat;
    
}

/**
    Basically achieves the same thing as randomRotation but through the use of
    quaternions. Pass in the seed value that you want to change.
 */
vector quatRotateRandom(vector angles; vector seed){
    vector rotations = set(
        randFloat(3.14 * i,1,2),
        randFloat(3.14 * i,1,3),
        randFloat(3.14 * i,1,4)
             
    );
    
    return qrotate(quaternion(rotations),seed);
    
}

// converts degree value to radians.
float toRadians(float degrees){
    return (deg * 3.14149) / 180.0;
}

