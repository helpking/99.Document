//
//  CoordinateMesh.cpp
//  021.FirstSample
//
//  Created by 何 利強 on 2015/09/15.
//
//

#include "CoordinateMesh.h"

USING_UIPARTS

// Csbファイルローダーを初期化する
CSB_INIT_LOADER(CoordinateMesh);

CoordinateMesh::CoordinateMesh()
{
    
}

CoordinateMesh::~CoordinateMesh()
{
    
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
void CoordinateMesh::onEnter()
{
    CsbBase::onEnter();
}