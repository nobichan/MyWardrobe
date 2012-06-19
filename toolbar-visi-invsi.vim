" Ctrl+F2 でツールバーとメニューバーをトグル
map <silent> <C-F2> :if &guioptions =~# 'T' <Bar>
                         \set guioptions-=T <Bar>
                         \set guioptions-=m <bar>

                    \else <Bar>
                         \set guioptions+=T <Bar>
                         \set guioptions+=m <Bar>

                    \endif<CR>

" メニューバーを非表示
"set guioptions-=m
" ツールバーを非表示
"set guioptions-=T
