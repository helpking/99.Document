//
//  CoordinateMesh.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#ifndef ___21_FirstSample__CoordinateMesh__
#define ___21_FirstSample__CoordinateMesh__

#include "UICommon.h"

namespace UParts
{
    
    class CoordinateMesh
    : public cocos2d::Layer
    {
    public:
        CREATE_FUNC(CoordinateMesh)
        CoordinateMesh();
        ~CoordinateMesh();
        // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
        virtual void onEnter() override;
        
    };
    
    class CoordinateMeshReader : public cocostudio::NodeReader
    {
    public:
        CoordinateMeshReader() {};
        ~CoordinateMeshReader() {};
        static CoordinateMeshReader* getInstance();
        static void purge();
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
    };
}

#endif /* defined(___21_FirstSample__CoordinateMesh__) */
