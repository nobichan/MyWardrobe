" for GNU global
" 後にキーワードを続けて検索
map <C-g> :Gtags
" 検索結果リストを行ったり来たり
map <C-n> :cn<CR>
map <C-p> :cp<CR>
" カーソル位置のトークンをキーワードに検索
map <C-j> :GtagsCursor<CR>
" 後にキーワードを続けてファイル名を検索
map <C-i> :Gtags -f %<CR>

