" VimをVisualStudioの外部ツールにする
" Visual Studio の操作
"   ツール(T)-外部ツール　追加(A)
"   　タイトル、コマンド、引数　を入力
gvim.exe --servername VS_NET --remote-silent +$(CurLine) +$(CurCol) $(ItemPath)

   or

gvim.exe --servername VS_NET --remote-tab-silent +$(CurLine) +$(CurCol) $(ItemPath)

