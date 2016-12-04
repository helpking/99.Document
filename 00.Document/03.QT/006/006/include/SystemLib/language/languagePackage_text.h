#ifndef LANGUAGE_PACKAGE_TEXT_H
#define LANGUAGE_PACKAGE_TEXT_H

#include "include/SystemLib/language/languagePackage_types.h"

namespace SystemLib {

/** \brief 语言文本 */
static TLanguageTextInfo LangeTextInfo[kTLanguageTextIdMax] = {
    { kTLanguageTextIdMenuFile, {"File", "文件", "ファイル"} },
    { kTLanguageTextIdMenuFileActionNew, {"File", "文件", "ファイル"} },
    { kTLanguageTextIdMenuFileActionOpen, {"Open", "打开", "オープン"} },
    { kTLanguageTextIdMenuFileActionSaveAs, {"SaveAs", "另存", "保存"} },
    { kTLanguageTextIdMenuAbout, {"About", "About", "About"} },
    { kTLanguageTextIdMenuAboutActionLanguage, {"About", "About", "About"} },
    { kTLanguageTextIdMenuAboutActionHelp, {"Help", "帮助", "ヘルプ"} }
};

}

#endif // LANGUAGE_PACKAGE_TEXT_H
