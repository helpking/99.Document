#ifndef LANGUAGE_PACKAGE_TYPES_H
#define LANGUAGE_PACKAGE_TYPES_H

#include "include/common_types.h"

namespace SystemLib {

/**
 * @brief 语言定义
 */
typedef enum {
    kTLanguageInvalid = kValueInvalid,
    /** \brief 英语 */
    kTLanguageEnglish,
    /** \brief 中文 */
    kTLanguageChinese,
    /** \brief 日语 */
    kTLanguageJapanese,
    kTLanguageMax,
    /** \brief 默认语言 */
    kTLanguageDefault = kTLanguageEnglish
}TLanguage;

/**
 * @brief 语言文本ID定义
 */
typedef enum {
    kTLanguageTextIdInvalid = kValueInvalid,
    /** \brief 菜单：File */
    kTLanguageTextIdMenuFile,
    /** \brief 菜单动作：File -> New */
    kTLanguageTextIdMenuFileActionNew,
    /** \brief 菜单动作：File -> Open */
    kTLanguageTextIdMenuFileActionOpen,
    /** \brief 菜单动作：File -> SaveAs */
    kTLanguageTextIdMenuFileActionSaveAs,
    /** \brief 菜单：About */
    kTLanguageTextIdMenuAbout,
    /** \brief 菜单动作：About -> Language */
    kTLanguageTextIdMenuAboutActionLanguage,
    /** \brief 菜单动作：About -> Help */
    kTLanguageTextIdMenuAboutActionHelp,
    kTLanguageTextIdMax
}TLanguageTextId;

/**
 * \brief 语言文本情报定义
 */
typedef struct TLanguageTextInfo{
    /** \brief 文本ID */
    TLanguageTextId TextId;
    /** \brief 语言文本 */
    const TChar* Text[kTLanguageMax];
}TLanguageTextInfo;

}

#endif // LANGUAGE_PACKAGE_TYPES_H
