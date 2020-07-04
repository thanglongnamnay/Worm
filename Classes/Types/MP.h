//
// Created by MacBook Pro on 5/24/20.
//

#ifndef WORM_MP_H
#define WORM_MP_H

#include <type_safe/strong_typedef.hpp>

namespace ts = type_safe;

struct MP : ts::strong_typedef<MP, int>,
			ts::strong_typedef_op::equality_comparison<MP>,
			ts::strong_typedef_op::relational_comparison<MP>,
			ts::strong_typedef_op::integer_arithmetic<MP> {
	using strong_typedef::strong_typedef;
};

#endif //WORM_MP_H
