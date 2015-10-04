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

NS_BEGIN_RESINFO_POOL

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
         * @brief パス
         */
        char* Path;
        
        S_RES_INFO()
        {
            // クリア
            clear();
        }
        
        /**
         * @brief クリア
         */
        void clear()
        {
            ResID = E_RES_ID::E_INVALID;
            ResType = E_RES_TYPE::E_INVALID;
            Path = nullptr;
        }
        
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
    S_RES_INFO getResInfo(const E_RES_ID iResId);
    
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
    
};

NS_END_RESINFO_POOL

#endif /* defined(___21_FirstSample__ResInfoPool__) */
