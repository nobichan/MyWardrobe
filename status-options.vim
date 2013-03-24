" ステータスライン常時表示
" 0 ... 非表示
" 1 ... ２つ以上の時表示
" 2 ... 常に表示
set laststatus=2

" ステータスラインに文字コードと改行文字を表示する
set statusline=%<%f\ %m%r%h%w\ \|%{(&fenc!=''?&fenc:&enc).'\|'.&ff.'\|'}%=%l,%c%V%8P

" mystatusinfo.vim より
set statusline=%{CurTabColor()}\ %<%F%h%m%r%h%w%y\ %{strftime(\"%c\",getftime(expand(\"%:p\")))}%=\ l:%l\,%L\ c:%c%V\ ps:%o\ hex:%b\ %P

" mystatusinfo.vim に文字コードと改行文字を追加
set statusline=%{CurTabColor()}\ %<%F%h%m%r%h%w%y\ \|%{(&fenc!=''?&fenc:&enc).'\|'.&ff.'\|'}\ %{strftime(\"%c\",getftime(expand(\"%:p\")))}%=\ l:%l\,%L\ c:%c%V\ ps:%o\ hex:%b\ %P

" strftime() を少し整理 && 追加
set statusline=%{CurTabColor()}\ %<%F%h%m%r%h%w%y\ \|%{(&fenc!=''?&fenc:&enc).'\|'.&ff.'\|'}\ %{strftime(\"%F\ (%a)\ (%V)\ %T\ %Z%z\")}%=\ l:%l\,%L\ c:%c%V\ ps:%o\ hex:%b\ %P

