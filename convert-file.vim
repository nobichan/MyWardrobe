GVim のメニューの編集

GVim のメニューは、$VIM/lang 配下にある。

Windowsだと、
・menu_ja.cp932.vim
・menu_ja_jp.cp932.vim
あたり。一応今でもUTF-8じゃなくてCP932らしい。

厳密には２番目のネーミングが正しいんだと思う。

ただしどちらも実体は同じディレクトリにある menu_japanese_japan.932.vim。

このファイルの下の方、295行目あたりから文字コード指定で読み書きするための
メニューがある。
CP932、EUC、iso-2022、UTF-8が揃っているが、最近見かけるようになったUCS-2が
未対応なので、それを追加する。

上から大きく分けて「読み込み」、「再読み込み」、「保存」の３ブロックに分かれて
いるので、それぞれのブロックの最後に追加する。
以下例。

299   " 読み込み
300   ・・・・・
309   an 10.396.100.130 &File.エンコード指定(&E)\.\.\..開く(&O)\.\.\..UTF-8(&8)<Tab>fenc=utf-8 :browse confirm e ++enc=utf-8<CR>
追加->an 10.396.100.140 &File.エンコード指定(&E)\.\.\..開く(&O)\.\.\..UCS-2(&2)<Tab>fenc=ucs-2 :browse confirm e ++enc=ucs-2<CR>
310 
311   " 再読込
312   ・・・・・
320   an 10.396.110.130 &File.エンコード指定(&E)\.\.\..再読込(&R)\.\.\..UTF-8(&8)<Tab>fenc=utf-8 :e ++enc=utf-8<CR>
追加->an 10.396.110.140 &File.エンコード指定(&E)\.\.\..再読込(&R)\.\.\..UCS-2(&2)<Tab>fenc=ucs-2 :e ++enc=ucs-2<CR>
321 
322   " 保存
323   ・・・・・
332   an 10.396.120.130 &File.エンコード指定(&E)\.\.\..保存(&S)\.\.\..UTF-8(&8)<Tab>fenc=utf-8 :set fenc=utf-8 \| w<CR>
追加->an 10.396.120.140 &File.エンコード指定(&E)\.\.\..保存(&S)\.\.\..UCS-2(&2)<Tab>fenc=ucs-2 :set fenc=ucs-2 \| w<CR>

