//
//  UtilsFileLoader.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/11.
//
//

#ifndef ___21_FirstSample__UtilsFileLoader__
#define ___21_FirstSample__UtilsFileLoader__

#include "CommonHeader.h"
#include "InterfaceMacro.h"
#include "FileLoader.h"

USING_NS_INTERFACE_LAB;

NS_BEGIN_NS_COMMON_UTILS

class UtilsFileLoader
: public FileLoader
{
public:
    
    /**
     * @brief コンストラクター
     */
    UtilsFileLoader();
    
    /**
     * @brief デストラクタ
     */
    ~UtilsFileLoader();
    
protected:
    
    /**
     * @brief リソースIDで、ファイルローダーを登録する
     * @param[in] iResId リソースID
     * @return 登録成功フラグ
     */
    virtual bool registFileLoaderObject(const ResInfoPool::E_RES_ID iResId) override;
    
    /**
     * @brief ロードされたファイルの情報をリセットする
     * @param[in] iPartsNode ロードされたファイルノード
     * @param[in] iContentSize コンテンツサイズ
     * @param[in] iResId リソースID
     */
    virtual void resetLoadFileInfo(Node* iLoaderFileNode,
                                   const Size& iContentSize,
                                   const ResInfoPool::E_RES_ID& iResId) override;
    
};

NS_END_NS_COMMON_UTILS


#endif /* defined(___21_FirstSample__UtilsLoad__) */
