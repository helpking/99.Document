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

　開発するには、最小限度をお勧めですが、自分に好きなUIインタフェースもインストールしてもいいかも
 
　①rootのパスワード
　　admin

  疑問：以下のSSHを設定しなくても、インタネットへもしくは、ホスト->ゲストへ ゲスト->ホストへのアクセスが自動でできてしまいました。
  MacでVirtualBoxにCentOS7をインストールしてSSH接続をするまでの方法
  http://koejima.com/archives/303/

  簡単メモ：
  virtualBox -> 環境設定 -> ネットワーク -> ホストオンリーネットワークで新しいホストオンリーを追加する（デフォルト名：vboxnet0）アドレス設定は以下です。
　　アドレス：192.168.56.1
　　ネットマスク：255.255.255.0
  仮マシンのIP設定
   アドレス：192.168.56.10
   ネットマスク：255.255.255.0
   ゲートウェイ：192.168.56.1

   検証には、CentOSを起動して、ブラウザで、インタネットをアクセスしてみてください。

３）VirtualBox を全画面（フルスクリーン）で表示する方法
　http://twakabay.blogspot.jp/2011/12/virtualboxcentos6.html
 
  1. Virtualboxのメニューから
  「デバイス」-「Guest Additions のインストール」を選択。
  2. デスクトップ上にGuest AditionsのCDイメージが表示されマウントされる
     PS:CentOSで、UIインタフェースをインストールされた場合、直接にインストールする用のダイアログが出てきます。以下のステープ3をやる必要がなくなります。
  3. 「アプリケーション」-「アクセサリ」-「端末」でターミナルウィンドウを開き、root権限で以下のコマンドを実行
    # cd /media/VBOXADDITIONS_4.1.8_75467
    # sh ./VBoxLinuxAdditions.run
  4. CentOSを再起動
   最大化しても、フルスクリーン表示にしても自動で画面が最適表示されるようになる

４）共有フォルダーの設定
  http://pc-karuma.net/virtualbox-folder-share/


