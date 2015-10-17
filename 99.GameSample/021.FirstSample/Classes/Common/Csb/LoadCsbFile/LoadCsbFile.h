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

USING_NS_CC;

NS_BEGIN_COMMON_CSB

enum class E_SCENE_ID
{
    E_INVALID = -1,
    
    /**
     * @brief トップシーン
     */
    E_TOP,
    E_MAX
};
/**
 * @brief Csbファイルをロードするクラス
 */
class LoadCsbFile
{
public:
    
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
    
protected:
    
    /**
     * @brief コンストラクター
     */
    LoadCsbFile();
    
    /**
     * @brief デストラクター
     */
    ~LoadCsbFile();
    
    /**
     * @brief シーンをロードする
     * @param[in] iSceneId シーンID
     */
    Node* loadScene(const E_SCENE_ID iSceneId);
    
private:
    static LoadCsbFile* _gInstance;
    
    /**
     * @brief Csbファイルをロードする
     * @param[in] iCsbFilePath Csbファイル
     */
    Node* loadFile(const char* iCsbFilePath);
};

NS_END_COMMON_CSB

#endif /* defined(___21_FirstSample__LoadCsbFile__) */
