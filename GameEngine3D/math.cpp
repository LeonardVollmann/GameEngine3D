//
//  math.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 16/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "math.h"

Vector3f Vector3f::rotate(const Quaternion &rot)
{
    Quaternion conj = rot.conjugate();
    Quaternion q = rot * (*this) * conj;
    
    Vector3f res = Vector3f(q.getX(), q.getY(), q.getZ());
    return res;
}