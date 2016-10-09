VirtualBoxの導入
http://pc-karuma.net/mac-virtualbox-install/

１）VirtualBoxインストール
　ダウンロードURL
　① http://www.oracle.com/technetwork/server-storage/virtualbox/downloads/index.html?ssSourceSiteId=otnjp
　② https://www.virtualbox.org/wiki/Downloads

２）CentOSのインストール
　ダウンロードURL
　https://www.centos.org/download/
　（推奨：64bit）
  MacでVirtualBoxにCentOS7をインストールしてSSH接続をするまでの方法
  http://www.task-notes.com/entry/20150524/1432436400
  
　①rootのパスワード
　　admin

３）VirtualBox を全画面（フルスクリーン）で表示する方法
　http://www.yocchi01.mydns.jp/webnote/centos6/bangai
 ①FAQ
  以下のような失敗の場合
　Could not mount the media/drive '/Applications/VirtualBox.app/Contents/MacOS/VBoxGuestAdditions.iso' (VERR_PDM_MEDIA_LOCKED).

　以下のコマンドで「virtualbox-guest-utils」をインストールしてください。
　sudo apt-get install virtualbox-guest-utils

　apt-getができない場合、finkをインストールしてください。
　http://qiita.com/yu-sa/items/351969b281f3aea5e03d
　
  finkインストールの成功チェック
  fink -v
  例：
　　Fink 0.41.0

　以下の場合、
　　command not found: fink
　　インストールしたfinkのフォルダー直下のbinフォルダーで、Finkファイルがあるかどうか
　　ある場合、システムのパスが正しく設定されていないです。
　　リンクを使って、好きな自分のbinへ指定してください。
　　例：
　　　$# ln -s ./fink /Users/b06685/bin 

　　リンク成功チェック
　　　$# ls -l /Users/b06685/bin 
     lrwxr-xr-x  1 b06685  CATK\Domain Users       6 10  9 19:33 fink -> ./fink

