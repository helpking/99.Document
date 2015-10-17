//
//  Singleton.h
//  021.FirstSample
//
//  Created by 何 利強 on 2015/10/17.
//
//

#ifndef ___21_FirstSample__Singleton__
#define ___21_FirstSample__Singleton__

#include "CommonHeader.h"

NS_BEGIN_NS_COMMON

/**
 * @brief シングルクラス
 */
template<class T>
class Singleton
{
public:
    /**
     * @brief シングルクラスのインスタンスを取得する
     */
    static inline T* getInstance()
    {
        if (!m_pInstance.get())
        {
            m_pInstance.reset (new T);
        }
        return m_pInstance.get();
    };
    
protected:
    Singleton(){};
    ~Singleton(){};
    
    Singleton(const Singleton&){};
    
    Singleton &operator = (const Singleton&){};
    
private:
    static std::auto_ptr<T> m_pInstance;
};

// 初期化
template <class T> std::auto_ptr<T> Singleton<T>::m_pInstance;

NS_END_NS_COMMON

#endif /* defined(___21_FirstSample__Singleton__) */
