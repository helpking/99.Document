
まず，Qtのライブラリを探すために，次の行をCMakeLists.txtに入れます。

　　find_package(Qt4 REQUIRED)

Qtでプログラムの開発を行うときに，GUI部品間のやり取り（通信）を行うために，signal/slotという機能を使います。それらのイン タフェースを記述するヘッダファイル（この例では，prog7.h)があるとき，次のような行を入れます。

    QT4_WRAP_CPP(prog7_h_moc ${prog7.h})

また，Qt Designerで作ったユーザインタフェースフィアル(この例では，prog7.ui)があるとき，次のような行を入れます。
   QT4_WRAP_UI(prog7_ui_h prog1.ui)

更に、アイコン等のリソースを管理するための.qrcファイル(この例では，prog7.urc)があるとき、次のような行を入れます。
　　QT4_ADD_RESOURCES(prog7_rccC prog7.qrc)

これらの設定内容をプログラムに結合させるために，次のような行を入れます。
　　include(${QT_USE_FILE})

便利のため，例え上記の機能を利用しない場合でも，空の *.h, *.uiと*.qrcを用意しましょう。そうすると，必要に応じて，上記の設定を追加したり，削除したりする手間を省くことができます。

注意事項：
１）Qtツールキットのインストール
　ダウンロードURL
　https://www.qt.io/download-open-source/

　アカウント
　helpking@hotmail.com/asdQWE123!”#

