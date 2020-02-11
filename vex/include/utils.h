

// sets magnitude for a vector
vector setMag(vector vec; float max){
    vec = normalize(vec);
    vec *= max;
    return vec;
}



float magSq(vector vec){
    return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
}

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
