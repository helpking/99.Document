Server 配置手順メモ

1) Node.jsのインストール
　　ダウンロード(v4.2.2/v4.2.1)URL:https://nodejs.org/en/
    注意：node.jsとnode-gypのバージョンが違う場合、インストール失敗の可能性があります。

　　インストール成功のチェック

　　Node was installed at

   　　/usr/local/bin/node

　　npm was installed at

   　　/usr/local/bin/npm

　　Make sure that /usr/local/bin is in your $PATH.

  バージョンチェックのコマンド
　node --version

  勉強資料
  -> Node.js教程 : http://www.yiibai.com/nodejs/

  ①  NodeJsのライブ、または、ツールのインストール
     --> express
         npm install -g express / npm uninstall express
     --> express-generator 
         npm install -g express-generator / npm uninstall express-generator 

         expressで、新規プロジェクトを作成する
         express -e  プロジェクト名(-e : ejs デフォルト：jade)

         作成してから、上記プロジェクトのデレクトリで、初期化として、以下のコマンドを実行してください。
         sudo npm install

         作成成功するかどうかのチェック
         以下のコマンドを実行してください。
         DEBUG=app ./bin/www

         ブラザで、以下のURLを入力してください。
         http://127.0.0.1:3000

     --> jade
         npm install -g jade / npm uninstall jade
     

2) python(2.5 < version < 3.0)

　バージョンチェックのコマンド
　python --version

3) C++コンパイラ
　Xcode Command Line Tools / XCode 
  XCode Command Line Tools インストール用のURL
  https://developer.apple.com/downloads/



PS:
 1) 参照資料
　　Pomeloマニアル：https://github.com/cynron/pomelo/wiki/中文文档首页
