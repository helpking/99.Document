#ifndef UI_TYPES_H
#define UI_TYPES_H

#include "include/common_types.h"
#include "include/language/languagePackage.h"

namespace UITypes {

/**
 * \brief Menu ID定义
 */
typedef enum {
    kTMenuIdInvalid = -1,
    /** \brief 文件 */
    kTMenuIdFile,
    /** \brief About */
    kTMenuIdAbout,
    kTMenuIdMax
}TMenuId;

/**
 * \brief Menu Action ID定义
 */
typedef enum {
    kTMenuActionIdInvalid = -1,
    /** \brief File:新文件 */
    kTMenuActionIdFileNew,
    /** \brief File:打开文件 */
    kTMenuActionIdFileOpen,
    /** \brief File:保存文件 */
    kTMenuActionIdFileSaveAs,
    /** \brief About:语言 */
    kTMenuActionIdAboutLanguage,
    /** \brief About:Help */
    kTMenuActionIdAboutHelp,
    kTMenuActionIdMax
}TMenuActionId;

/**
 * \brief Menu Action Info定义
 */
typedef struct TMenuActionInfo {
    /** \brief Action Id */
    CommonTypes::TS32 ActionId;
    /** \brief Action Text */
    CommonTypes::TChar* Text[Language::kTLanguageMax];
}TMenuActionInfo;

/**
 * \brief Menu Info定义
 */
typedef struct TMenuInfo {
    /** \brief Menu Id */
    TMenuId MenuId;
    /** \brief Menu Text */
    CommonTypes::TChar* Text[Language::kTLanguageMax];
    /** \brief Menu Text */
    TMenuActionInfo Actions[];
}TMenuInfo;

}

#endif // UI_TYPES_H
