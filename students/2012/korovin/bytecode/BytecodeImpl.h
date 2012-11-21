/*
 * BytecodeImpl.h
 *
 *  Created on: 24.10.2012
 *      Author: temp1ar
 */

#ifndef BYTECODEIMPL_H_
#define BYTECODEIMPL_H_

#include "mathvm.h"

namespace mathvm {

class BytecodeImpl: public Code {
public:
	BytecodeImpl();
	virtual ~BytecodeImpl();

	virtual Status* execute(vector<Var*>& vars);

	void executeFunction(BytecodeFunction* f);
};

template<typename T>
uint64_t compare(T v1, T v2) {
	if (v1 > v2)
		return 1;
	if (v1 == v2)
		return 0;
	if (v1 < v2)
		return -1;
	return 0;
}

} /* namespace mathvm */
#endif /* BYTECODEIMPL_H_ */