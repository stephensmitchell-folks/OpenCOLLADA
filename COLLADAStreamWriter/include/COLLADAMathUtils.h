/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_MATHUTIL_H__
#define __COLLADASTREAMWRITER_MATHUTIL_H__

#include "COLLADAPrerequisites.h"

#define TOLERANCE 0.001f

namespace COLLADA
{

    // A class that holds some static math utility functions

    class MathUtils
    {

    public:

        static const double COLLADA_PI;
        static const float COLLADA_PI_f;
        /*
        static const double PIff;
        static const double TWOPI;
        static const double HALFPI;
        */
        static const double COLLADA_DEG_TO_RAD;
        static const double COLLADA_RAD_TO_DEG;

        static const float DEG_TO_RAD_f;
        static const float RAD_TO_DEG_f;

        /** Returns true iff @a value1 and @a value2 are equal within the tolerance*/
        template<class T>
        static bool equals ( const T & value1, const T & value2 )
        {
            return value1 - value2 < TOLERANCE && value1 - value2 > -TOLERANCE;
        }


        /** Returns true iff @a value1, @a value2 and @a value3 are equal within the tolerance*/
        template<class T>
        static bool equals3 ( const T & value1, const T & value2, const T & value3 )
        {
            return equals ( value1, value2 ) && equals ( value2, value3 ) &&equals ( value3, value1 );
        }


        /** Returns true iff @a value is equal to zero within the tolerance*/
        static bool equalsZero ( const float & value )
        {
            return equals ( value, 0.0f );
        }

        /** Returns true iff @a value is equal to zero within the tolerance*/
        static bool equalsZero ( const double & value )
        {
            return equals ( value, 0.0 );
        }

        template<class T>
        static double radToDeg ( const T & value )
        {
            return value * COLLADA_RAD_TO_DEG;
        }

        template<class T>
        static double degToRad ( const T & value )
        {
            return value * COLLADA_DEG_TO_RAD;
        }

        template<class T>
        static float radToDegF ( const T & value )
        {
            return value * RAD_TO_DEG_f;
        }

        template<class T>
        static float degToRadF ( const T & value )
        {
            return value * DEG_TO_RAD_f;
        }

        /** Retrieves the sign of a number.
        @param val The number to check.
        @return 1 if positive, -1 if negative. */
        template <class T>
        static T sign ( const T& val )
        {
            return ( val >= T ( 0 ) ) ? T ( 1 ) : T ( -1 );
        }

        /** Clamps the specified object within a range specified by two other objects
        of the same class.
        Clamping refers to setting a value within a given range. If the value is
        lower than the minimum of the range, it is set to the minimum; same for
        the maximum.
        @param val The object to clamp.
        @param mx The highest object of the range.
        @param mn The lowest object of the range.
        @return The clamped value. */
        template <class T, class T2, class T3>
        static T clamp ( T val, T2 mn, T3 mx )
        {
            return ( T ) ( ( val > ( T ) mx ) ? ( T ) mx : ( val < ( T ) mn ) ? ( T ) mn : val );
        }

    };

}

#endif // #define __COLLADASTREAMWRITER_MATHUTIL_H__