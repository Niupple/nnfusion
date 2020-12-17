#pragma once

#include "../op.hpp"
#include <map>
#include <utility>

namespace nnfusion
{
    namespace op
    {
        class Cast : public Op
        {
        public:
            Cast() = delete;
            Cast(const nnfusion::Shape& shape, const element::Type &itype, const element::Type &otype);

        public:
            enum CastType
            {
                FLOAT_TO_HALF,
                HALF_TO_FLOAT,
            };
            const static std::map<std::pair<element::Type, element::Type>, CastType> DTYPES_TO_CAST_TYPE;

        private:
            element::Type m_input_dtype, m_output_dtype;
            CastType m_ctype;
            Shape m_shape;

            bool infer_cast_type();
        };
    }   // namespace op
}   // namespace nnfusion