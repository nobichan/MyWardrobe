" set list で表示する文字
listchars=tab:>-,eol:$,trail:~,precedes:>,extends:<,nbsp:@
" タブ : >----
" 行末 : $
" 行末の空白 : ~
" wrap 時の行頭 : >
" wrap 時の行末 : <
" 空白 : @

" ハードタブと行末のスペースを表示
highlight SpecialKey ctermfg=blue guifg=#555555
set listchars=tab:>\ ,trail:_
set list

