//
//  InterfaceMacro.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/14.
//
//

#ifndef _21_FirstSample_InterfaceMacro_h
#define _21_FirstSample_InterfaceMacro_h

#include "cocos2d.h"

#pragma mark -
#pragma mark ゲームツールライブ区分

#define GAME_TOOL_LAB_COCOSSTUDIO                   1
#define GAME_TOOL_LAB_KBN                           1

#pragma mark -
#pragma mark ヘッダーファイル及びNameSpace(共通)

#define USING_NS_CC_UI                              using namespace cocos2d::ui

#pragma mark -
#pragma mark ヘッダーファイル、NameSpace及びマクロ(CocosStudio)
USING_NS_CC;
USING_NS_CC_UI;
USING_NS_CC_MATH;

#if (GAME_TOOL_LAB_KBN == GAME_TOOL_LAB_COCOSSTUDIO)

#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

// cocostudio
#define USING_NS_COCOS_STUDIO                       using namespace cocostudio

// namespace
USING_NS_COCOS_STUDIO;

/**
 * @brief 指定されたノード名で、ルートロードから、ノードを探す
 * @param[in] iSearchRootNode 1
 * @param[in] iNodeName 1
 * @return 探したいノード
 */
Node* IRTNodeSearch(Node* iSearchRootNode, const char* iNodeName);

// 変数の自動設定マクロ
#define FILE_MEMBER_VARIABLE_ASSIGNER(TARGET, MEMBERNAME, MEMBERTYPE, MEMBER) \
        if ( TARGET && (strcmp(MEMBERNAME, "") != 0) ) \
        { \
            MEMBER = static_cast<MEMBERTYPE>(IRTNodeSearch(TARGET,MEMBERNAME)); \
        }

//! ファイルローダーを作成する
#define FILE_LOADER_CREATE(__CLASS_NAME__)          class __CLASS_NAME__; \
                                                    class __CLASS_NAME__##Reader : public NodeReader \
                                                    { \
                                                        public: \
                                                            __CLASS_NAME__##Reader() {}; \
                                                            ~__CLASS_NAME__##Reader() {}; \
                                                            inline static __CLASS_NAME__##Reader* getInstance() \
                                                            { \
                                                                if (!_instance) \
                                                                { \
                                                                    _instance = new __CLASS_NAME__##Reader(); \
                                                                } \
                                                                return _instance; \
                                                            } \
                                                            inline static void purge() { CC_SAFE_DELETE(_instance); }; \
                                                            inline cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions) \
                                                            { \
                                                                __CLASS_NAME__* node = __CLASS_NAME__::create(); \
                                                                setPropsWithFlatBuffers(node, nodeOptions); \
                                                                return node; \
                                                            } \
                                                        private: \
                                                            static __CLASS_NAME__##Reader* _instance; \
                                                    };

//! ファイルローダーを初期化にする
#define FILE_LOADER_INIT(__CLASS_NAME__)            __CLASS_NAME__##Reader* __CLASS_NAME__##Reader::_instance = nullptr;

#endif

#pragma mark -
#pragma mark NameSpace：InterfaceLab

#define USING_NS_INTERFACE_LAB                      using namespace InterfaceLab
#define NS_BEGIN_NS_INTERFACE_LAB                   namespace InterfaceLab {
#define NS_END_NS_INTERFACE_LAB                     }

#endif
