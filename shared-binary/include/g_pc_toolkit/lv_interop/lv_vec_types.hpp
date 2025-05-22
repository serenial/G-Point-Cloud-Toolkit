#pragma once

#include <pcl/point_types.h>

#include "./lv_types.hpp"
#include "./lv_array_1d.hpp"

namespace g_pc_toolkit
{
    namespace lv_interop
    {

#include "./set_packing.hpp"
        
        struct LV_ImagePointFloat_t{
            double m_x,m_y;
            operator pcl::PointXY() const;
            operator pcl::PointXYZ() const; // 2d points as 3d
            LV_ImagePointFloat_t& operator=(const pcl::PointXY &);
            LV_ImagePointFloat_t& operator=(const double[2]);
            LV_ImagePointFloat_t& copy_from(const float*);
        };

        struct LV_ImagePointInt_t{
            int32_t m_x,m_y;
            LV_ImagePointInt_t& copy_from(const int*);
        };


        struct LV_Vec3Double_t{
            double m_x,m_y,m_z;
            operator pcl::PointXYZ() const;
            LV_Vec3Double_t& operator=(const float[3]);
            LV_Vec3Double_t& operator=(const pcl::PointXYZ &);
        };

using LV_ImagePointFloatPtr_t = LV_Ptr_t<LV_ImagePointFloat_t>;
using LV_ImagePointIntPtr_t = LV_Ptr_t<LV_ImagePointInt_t>;

using LV_ObjectPointFloat_t = LV_Vec3Double_t;
using LV_ObjectPointFloatPtr_t = LV_Ptr_t<LV_ObjectPointFloat_t>;

#include "./reset_packing.hpp"
    }

}