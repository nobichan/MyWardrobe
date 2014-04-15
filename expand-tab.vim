" vimで保存時にタブをスペースに変換する方法
set expandtab
" とするとスペースに変換
set noexpandtab
" とすると変換しない

" .vimrc で↓こんな風にしておくと、:Expand とかするだけで
" スペースに変換できる
function! s:Expand()
    :set expandtab
    :%retab!
    :set noexpandtab
endfunction

command! -nargs=0 Expand call s:Expand()

