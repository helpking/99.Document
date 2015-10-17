//
//  GMacro.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef ___21_FirstSample__GMacro__
#define ___21_FirstSample__GMacro__

#include "UICommon.h"

#define USING_COMMON                         using namespace Common;
#define NS_BEGIN_COMMON                      namespace Common {
#define NS_END_COMMON                        }

#define USING_COMMON_CSB                     using namespace Common::Csb;
#define NS_BEGIN_COMMON_CSB                  namespace Common {                     \
                                                 namespace Csb {
#define NS_END_COMMON_CSB                        }                                  \
                                             }

// 変数の自動設定マクロ
#define CSB_MEMBER_VARIABLE_ASSIGNER(TARGET, MEMBERNAME, MEMBERTYPE, MEMBER)        \
if ( TARGET && (strcmp(MEMBERNAME, "") != 0) )                                      \
{                                                                                   \
MEMBER = static_cast<MEMBERTYPE>(TARGET->getChildByName(MEMBERNAME));               \
}
//! CCSファイルローダーを作成する
#define CSB_CREATE_LOADER(__CLASS_NAME__)           class __CLASS_NAME__##Reader : public cocostudio::NodeReader                                \
                                                    {                                                                                           \
                                                    public:                                                                                     \
                                                        __CLASS_NAME__##Reader() {};                                                            \
                                                        ~__CLASS_NAME__##Reader() {};                                                           \
                                                        inline static __CLASS_NAME__##Reader* getInstance()                                     \
                                                        {                                                                                       \
                                                            if (!_instance)                                                                     \
                                                            {                                                                                   \
                                                                _instance = new __CLASS_NAME__##Reader();                                       \
                                                            }                                                                                   \
                                                            return _instance;                                                                   \
                                                        }                                                                                       \
                                                        inline static void purge() { CC_SAFE_DELETE(_instance); };                              \
                                                        inline cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)  \
                                                        {                                                                                       \
                                                            __CLASS_NAME__* node = __CLASS_NAME__::create();                                    \
                                                            setPropsWithFlatBuffers(node, nodeOptions);                                         \
                                                            return node;                                                                        \
                                                        }                                                                                       \
                                                    private:                                                                                    \
                                                        static __CLASS_NAME__##Reader* _instance;                                               \
                                                    };

#define CSB_INIT_LOADER(__CLASS_NAME__)            __CLASS_NAME__##Reader* __CLASS_NAME__##Reader::_instance = nullptr;


#endif /* defined(___21_FirstSample__GMacro__) */
