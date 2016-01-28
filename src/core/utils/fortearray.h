/*******************************************************************************
 * Copyright (c) 2015 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef FORTEARRAY_H_
#define FORTEARRAY_H_

#include <datatype.h>
#include <assert.h>

namespace forte {
  namespace core {
    namespace util {


      /*!\brief Simple array class allowing to implement more save arrays.
       *
       * This class is aligned to the std::array.
       * Consider to use std:array when stl support gets better on all supported platforms.
       */
      template<typename T, size_t Capacity>
      class CArray{
        public:
          T& operator [](size_t paIndex){
            assert(paIndex < Capacity);
            return mData[paIndex];
          }

          size_t getSize(){
            return Capacity;
          }

        private:
          T mData[Capacity];
      };

    } // namespace util
  } // namespace core
}  // namespace forte

#endif /* FORTEARRAY_H_ */
