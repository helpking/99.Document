//
//  ResInfoPool.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef ___21_FirstSample__ResInfoPool__
#define ___21_FirstSample__ResInfoPool__

#include "ManagerHeader.h"

NS_BEGIN_RESINFO

class ResInfoPool
{
public:
    
    /**
     * @breif リソースID
     */
    enum class E_RES_ID
    {
        E_INVALID = -1,
        E_SCENE_TOP,
        E_PARTS_COORDINATE_MESH,
        E_PARTS_DEMO_PLAYER,
        E_PARTS_ROLE,
        E_PARTS_WINDMILL,
        E_MAX
    };
    
    /**
     * @breif リソースタイプ
     */
    enum class E_RES_TYPE
    {
        E_INVALID = -1,
        
        /**
         * @brief シーン
         */
        E_SCENE,
        
        /**
         * @brief パーツ
         */
        E_PARTS,
        
        /**
         * @brief 画像
         */
        E_IMAGE,
        
        /**
         * @brief アイコン
         */
        E_ICON,
        E_MAX
    };
    
    /**
     * @breif リソース情報
     */
    typedef struct S_RES_INFO
    {
        /**
         * @brief リソースID
         */
        E_RES_ID ResID;
        
        /**
         * @breif リソースタイプ
         */
        E_RES_TYPE ResType;
        
        /**
         * @brief 名称
         */
        std::string Name;
        
        /**
         * @brief パス
         */
        std::string Path;
                
    }S_RES_INFO;
    
    /**
     * @brief コンストラクター
     */
    ResInfoPool();
    
    /**
     * @brief デストラクタ
     */
    ~ResInfoPool();
    
    /**
     * @brief リソース情報を追加する
     * @param[in] iResId リソースID
     */
    S_RES_INFO getResInfoBySceneId(const E_RES_ID iResId);
    
    /**
     * @brief リソース情報を追加する
     * @param[in] iResId リソースID
     */
    S_RES_INFO getResInfo(const E_RES_ID iResId);
    
    /**
     * @breif リソース情報が無効かどうかの判定
     * @return true : 無効 / false : 有効
     */
    inline bool isResInfoInvalid(const S_RES_INFO& iResInfo)
    {
        return (E_RES_ID::E_INVALID == iResInfo.ResID);
    };
    
protected:
    
    /**
     * @brief リソース情報を追加する
     * @param[in] iResId リソースID
     * @param[in] iResInfo リソース情報
     */
    void addResInfo(const E_RES_ID iResId,
                    const S_RES_INFO iResInfo);
    
private:
    
    //! リソースプール
    std::map<E_RES_ID, S_RES_INFO> _resInfoPool;
    
    /**
     * @brief 初期化する
     */
    void init();
    
    /**
     * @brief リソース情報を初期化する
     * @param[in] iResInfo リソース情報
     */
    void initResInfo(S_RES_INFO& iResInfo);
    
};

NS_END_RESINFO

#endif /* defined(___21_FirstSample__ResInfoPool__) */
