#include "cast.hpp"

using namespace std;
using namespace nnfusion::op;

Cast::Cast(const nnfusion::Shape& shape, const element::Type &itype, const element::Type &otype)
: Op("Cast")
, m_shape(shape)
, m_input_dtype(itype)
, m_output_dtype(otype) {
    infer_cast_type();
}

const std::map<std::pair<element::Type, element::Type>, Cast::CastType> Cast::DTYPES_TO_CAST_TYPE = {
    {{element::f16, element::f32}, Cast::HALF_TO_FLOAT},
    {{element::f32, element::f16}, Cast::FLOAT_TO_HALF},
};


bool Cast::infer_cast_type()
{
    auto p = DTYPES_TO_CAST_TYPE.find(std::make_pair(m_input_dtype, m_output_dtype));
    if (p == DTYPES_TO_CAST_TYPE.end())
    {
        NNFUSION_CHECK_FAIL() << "Type Casting from (" << m_input_dtype.c_type_string() << ") to (" << m_output_dtype.c_type_string() << ") does not exist.";
        return false;
    }
    else
    {
        m_ctype = p->second;
        return true;
    }
}

