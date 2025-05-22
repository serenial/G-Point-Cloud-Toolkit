#include <g_pc_toolkit/lv_interop/lv_vec_types.hpp>

using namespace g_pc_toolkit;
using namespace lv_interop;

LV_ImagePointFloat_t::operator pcl::PointXY() const
{
    return pcl::PointXY(m_x, m_y);
}

LV_ImagePointFloat_t &LV_ImagePointFloat_t::operator=(const pcl::PointXY &point)
{
    m_x = point.x;
    m_y = point.y;
    return *this;
}

LV_ImagePointFloat_t &LV_ImagePointFloat_t::operator=(const double array[2])
{
    m_x = array[0];
    m_y = array[1];
    return *this;
}

LV_ImagePointFloat_t &LV_ImagePointFloat_t::copy_from(const float *element_ptr)
{
    m_x = *element_ptr++;
    m_y = *element_ptr;
    return *this;
}

LV_ImagePointInt_t &LV_ImagePointInt_t::copy_from(const int *element_ptr)
{
    m_x = *element_ptr++;
    m_y = *element_ptr;
    return *this;
}

LV_Vec3Double_t::operator pcl::PointXYZ() const
{
    return pcl::PointXYZ{static_cast<float>(m_x), static_cast<float>(m_y), static_cast<float>(m_z)};
}

LV_Vec3Double_t &LV_Vec3Double_t::operator=(const float a[3])
{
    m_x = a[0];
    m_y = a[1];
    m_z = a[2];
    return *this;
}
LV_Vec3Double_t &LV_Vec3Double_t::operator=(const pcl::PointXYZ &p)
{
    m_x = p.x;
    m_y = p.y;
    m_z = p.z;
    return *this;
}