#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "include/common_types.h"

namespace Language {

/**
 * @brief 语言定义
 */
typedef enum {
    kTLanguageInvalid = -1,
    /** \brief 英语 */
    kTLanguageEnglish,
    /** \brief 中文 */
    kTLanguageChinese,
    /** \brief 日语 */
    kTLanguageJapanese,    
    /** \brief 默认语言 */
    kTLanguageDefault = kTLanguageEnglish,
    kTLanguageMax
}TLanguage;

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
}

}

#endif // LANGUAGE_H
