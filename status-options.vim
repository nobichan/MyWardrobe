" ステータスライン常時表示
" 0 ... 非表示
" 1 ... ２つ以上の時表示
" 2 ... 常に表示
set laststatus=2

" ステータスラインに文字コードと改行文字を表示する
set statusline=%<%f\ %m%r%h%w\ \|%{(&fenc!=''?&fenc:&enc).'\|'.&ff.'\|'}%=%l,%c%V%8P
