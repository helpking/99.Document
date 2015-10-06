//
//  LoadCsbFile.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef ___21_FirstSample__LoadCsbFile__
#define ___21_FirstSample__LoadCsbFile__

#include "CsbMacro.h"
#include "ResInfoPool.h"

USING_NS_CC;
USING_NS_RESINFO;

NS_BEGIN_COMMON_CSB

/**
 * @brief Csbファイルをロードするクラス
 */
class LoadCsbFile
{
public:
    
    /**
     * @brief コンストラクター
     */
    LoadCsbFile();
    
    /**
     * @brief デストラクター
     */
    ~LoadCsbFile();
    
    /**
     * @brief インスタンスを取得する
     * @return インスタンス
     */
    inline static LoadCsbFile* getIntance()
    {
        if (_gInstance == nullptr)
        {
            _gInstance = new LoadCsbFile();
        }
        
        return _gInstance;
    };
    
    /**
     * @brief シーンをロードする
     * @param[in] iSceneId シーンID
     */
    Node* loadScene(const ResInfoPool::E_RES_ID iSceneId);
    
    /**
     * @brief Csbファイルをロードする
     * @param[in] iPartsId パーツID
     */
    Node* loadParts(const ResInfoPool::E_RES_ID iPartsId);
    
protected:
    

    
private:
    static LoadCsbFile* _gInstance;
    
};

NS_END_COMMON_CSB

#endif /* defined(___21_FirstSample__LoadCsbFile__) */
