#ifndef UI_TYPES_H
#define UI_TYPES_H

#include "include/common_types.h"
#include "include/language/languagePackage_types.h"
#include "include/language/languagePackage_text.h"

namespace UITypes {

/**
 * \brief Menu ID定义
 */
typedef enum {
    kTMenuIdInvalid = kValueInvalid,
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
    kTMenuActionIdInvalid = kValueInvalid,
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
    TS32 ActionId;
    /** \brief Action TextId */
    const Language::TLanguageTextId TextId;
}TMenuActionInfo;

/** \brief Menu最大Action数 */
const TS32 kMaxMenuActionsCount = 10;
/**
 * \brief Menu Info定义
 */
typedef struct TMenuInfo {
    /** \brief Menu Id */
    TMenuId MenuId;
    /** \brief Menu TextId */
    const Language::TLanguageTextId TextID;
    /** \brief Action Ids */
    TMenuActionId ActionIds[kMaxMenuActionsCount];
}TMenuInfo;

/** \brief 菜单定义 */
static TMenuInfo menusInfo[] = {
    {
        kTMenuIdFile, Language::kTLanguageTextIdMenuFile,
        {
            kTMenuActionIdFileNew,
            kTMenuActionIdFileOpen,
            kTMenuActionIdFileSaveAs,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid
        }
    },
    {
        kTMenuIdAbout, Language::kTLanguageTextIdMenuAbout,
        {
            kTMenuActionIdAboutLanguage,
            kTMenuActionIdAboutHelp,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid,
            kTMenuActionIdInvalid
        }
    }
};

/** \brief Action定义 */
static TMenuActionInfo menuActionsInfo[] = {
    { kTMenuActionIdFileNew, Language::kTLanguageTextIdMenuFileActionNew },
    { kTMenuActionIdFileOpen, Language::kTLanguageTextIdMenuFileActionOpen },
    { kTMenuActionIdFileSaveAs, Language::kTLanguageTextIdMenuFileActionSaveAs },
    { kTMenuActionIdAboutLanguage, Language::kTLanguageTextIdMenuAboutActionLanguage },
    { kTMenuActionIdAboutHelp, Language::kTLanguageTextIdMenuAboutActionHelp }
};

}

#endif // UI_TYPES_H
