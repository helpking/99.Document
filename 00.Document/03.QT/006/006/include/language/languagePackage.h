#ifndef LANGUAGE_PACKAGE_H
#define LANGUAGE_PACKAGE_H

#include <QtGlobal>

#include "include/common.h"
#include "include/language/languagePackage_types.h"
#include "include/language/languagePackage_text.h"

namespace Language {

/**
 * \brief 语言包
 **/
class languagePackage {
public:
    static languagePackage* instance_;
    static languagePackage* getInstance();
    ~languagePackage();

    /**
     * \brief 加载语言包
     * \param[in] iLanguage 语言
     */
    void loadLanguagePackage(const TLanguage iLanguage = kTLanguageDefault);

    /**
     * \brief 取得语言
     * \return 语言
     */
    _INLINE TLanguage GetLanguage() const;

    /**
     * \brief 语言设定
     * \param[in] iLanguage 语言
     */
    _INLINE void SetLanguage(const TLanguage iLanguage);

    /**
     * \brief 语言文本取得
     * \param[in] iTxtId 文本ID
     */
    _INLINE const TChar* GetText(const TLanguageTextId iTxtId) const;

protected:
    languagePackage();

private:
    /** \brief 当前语言 */
    TLanguage language_;
};

_INLINE TLanguage languagePackage::GetLanguage() const {
    return this->language_;
};
_INLINE void languagePackage::SetLanguage(const TLanguage iLanguage) {
    this->language_ = iLanguage;
};
_INLINE const TChar* languagePackage::GetText(const TLanguageTextId iTxtId) const {
    Q_ASSERT_X((LangeTextInfo[iTxtId].TextId == iTxtId), __FUNCTION__, "The text id is invalid!!!");
    return LangeTextInfo[iTxtId].Text[this->language_];
};

}

#endif // LANGUAGE_PACKAGE_H
