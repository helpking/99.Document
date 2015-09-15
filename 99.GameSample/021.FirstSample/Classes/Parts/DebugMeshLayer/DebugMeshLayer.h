//
//  DebugMeshLayer.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#ifndef ___21_FirstSample__DebugMeshLayer__
#define ___21_FirstSample__DebugMeshLayer__

#include "UCommon.h"

namespace UParts
{
    
    class DebugMeshLayer
    : public cocos2d::Layer
    {
    public:
        CREATE_FUNC(DebugMeshLayer)
        DebugMeshLayer();
        ~DebugMeshLayer();
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
    };
    
    class DebugMeshLayerReader : public cocostudio::NodeReader
    {
    public:
        DebugMeshLayerReader() {};
        ~DebugMeshLayerReader() {};
        static DebugMeshLayerReader* getInstance();
        static void purge();
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
    };
}

#endif /* defined(___21_FirstSample__DebugMeshLayer__) */
