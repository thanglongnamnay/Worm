//
// Created by MacBook Pro on 5/24/20.
//

#ifndef WORM_HP_H
#define WORM_HP_H

#include <type_safe/strong_typedef.hpp>

namespace ts = type_safe;

struct HP : ts::strong_typedef<HP, unsigned>
        , ts::strong_typedef_op::equality_comparison<HP>
        , ts::strong_typedef_op::relational_comparison<HP>
        , ts::strong_typedef_op::integer_arithmetic<HP> {
    using strong_typedef::strong_typedef;
};

#endif //WORM_HP_H
