" Ctrl+F2 �Ńc�[���o�[�ƃ��j���[�o�[���g�O��
map <silent> <C-F2> :if &guioptions =~# 'T' <Bar>
                         \set guioptions-=T <Bar>
                         \set guioptions-=m <bar>

                    \else <Bar>
                         \set guioptions+=T <Bar>
                         \set guioptions+=m <Bar>

                    \endif<CR>

" ���j���[�o�[���\��
"set guioptions-=m
" �c�[���o�[���\��
"set guioptions-=T
