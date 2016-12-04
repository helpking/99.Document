#include "include/SystemLib/language/languagePackage.h"
#include "include/ui/ui_types.h"

namespace SystemLib {

languagePackage* languagePackage::instance_ = nullptr;



languagePackage* languagePackage::getInstance() {
    if(instance_ == nullptr) {
        instance_ = new languagePackage();
    }
    return instance_;
}

languagePackage::languagePackage()
    : language_(kTLanguageDefault) {

}

languagePackage::~languagePackage() {

}

/**
 * \brief 加载语言包
 * \param[in] iLanguage 语言
 */
void languagePackage::loadLanguagePackage(const TLanguage iLanguage /*= kTLanguageDefault */) {
    // 设置语言
    this->SetLanguage(iLanguage);
}

}
