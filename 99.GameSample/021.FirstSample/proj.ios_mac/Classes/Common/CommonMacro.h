//
//  CommonMacro.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/14.
//
//

#ifndef _21_FirstSample_CommonMacro_h
#define _21_FirstSample_CommonMacro_h

#include "InterfaceMacro.h"

#define USING_NS_COMMON                         using namespace Common
#define NS_BEGIN_NS_COMMON                      namespace Common {
#define NS_END_NS_COMMON                        }

#define USING_NS_COMMON_UTILS                   using namespace Common::Utils
#define NS_BEGIN_NS_COMMON_UTILS                namespace Common { \
                                                    namespace Utils {
#define NS_END_NS_COMMON_UTILS                      } \
                                                }

#endif
