//
//  LoadFileBase.h
//  021.FirstSample
//
//  Created by 何利强 on 15-10-10.
//
//

#ifndef _21_FirstSample_LoadFileBase_h
#define _21_FirstSample_LoadFileBase_h

#include "InterfaceLab.h"

NS_BEGIN_NS_INTERFACE_LAB

class LoadFileBase
: public Node
, public WidgetCallBackHandlerProtocol
{
public:
    LoadFileBase();
    ~LoadFileBase();
    
    virtual void onEnter() override;
    virtual void onExit() override;
    
    virtual Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName) override;
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName) override;
    virtual Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName) override;
    virtual void onLoadFileTouch(Ref* sender, Widget::TouchEventType type, const std::string &callBackName);
    virtual void onLoadFileClick(Ref* sender, const std::string &callBackName);
    virtual void onLoadFileEvent(Ref* sender, int eventType, const std::string &callBackName);
    
    /**
     * @brief ロードファイルで指定された、変数一覧を初期化にする
     */
    virtual void initLoadFileMemberInfo();
    
    /**
     * @brief タッチコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetTouchCallback initOnTouchCallbackInfo(const std::string& iCallBackName);
    
    /**
     * @brief クリックコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetClickCallback initOnClickCallbackInfo(const std::string& iCallBackName);
    
    /**
     * @brief イベントコールバックの初期化
     * @param[in] iCallBackName コールバック名
     */
    virtual Widget::ccWidgetEventCallback initOnEnentCallbackInfo(const std::string& iCallBackName);
    
    
    /**
     * @brief ロードファイルより、ベイスサイズを取得する
     * @return ベイスサイズ
     */
    inline Size getBaseSize()
    {
        return this->getContentSize();
    };
    
protected:
    
    /**
     * @brief ロードファイルの情報を初期化する
     */
    virtual void initLoadFileInfo();
    
    /**
     * @brief ZOrderの情報を
     */
    virtual void initZOrderInfo() {};
    
    /**
     * @brief ベイスノードを取得する
     * @return ベイスノード
     */
    inline cocos2d::Node* getBaseNode()
    {
        return this->BaseNode_;
    };
    
private:
    
    //! ベイスノード
    Node* BaseNode_;
};

NS_END_NS_INTERFACE_LAB

#endif
