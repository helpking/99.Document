
prog6.ccは，OpenGLとGLUTという２つのライブラリを利用するので，これらのライブラリを探すがめ に，CMakeLists.txtに
    find_package(GLUT)
    find_package(OpenGL)
の２行を追加します。
（find_packageで探せるライブラリとその名前は，一般的に/usr/share/cmake/Modules/
 (MAC:/usr/local/share/cmake/Modules)の 下にある Findライブラリ名.cmake で確認できます。）

prog6とこの２つのライブラリと数学ライブラリとリンクするために、次の行
    target_link_libraries(prog6 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
をCMakeList.txtに追加します。
出来上がったCMakeLists.txtは次の通りです。

