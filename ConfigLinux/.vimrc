"------------Auto load / install plugin manager-------------"

if !1 | finish | endif

" auto-install vim-plug
if empty(glob('~/.vim/autoload/plug.vim'))
    echo "Installing VimPlug..."
    silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
    autocmd VimEnter * PlugInstall
endif

"---------------Reglage General---------------"

colorscheme atlantis
syntax on
set list " Affiche les caracteres non imprimable
set mouse=a " Rend la souris utilisable dans vim
setlocal nolist "Set les differents symbole pour le caracteres non imprimable$
set nu " Affiche les numeros des lignes
set tabstop=4    " --
set shiftwidth=4 " ----- regle la tabulation sur 4 et la regle pour adapter le texte au tabulation presente
set smartindent  " --
set autoindent " indentation automatique lors du saut a la ligne
set encoding=utf-8
set backspace=indent,eol,start " Force le comportement normal de backspace
set pumheight=10
packadd! termdebug
let g:termdebug_wide=1
autocmd FileType apache setlocal commentstring=#\ %s

" ---------------Mapping------------------"

" surround
map <C-p>				<ESC>ysiw
map <C-m>				<ESC>ds
map <C-o>				<ESC>yss
map <C-l>				<ESC>cs

noremap <C-c>				<ESC>:NERDTreeToggle<CR>
inoremap <C-c>				<ESC>:NERDTreeToggle<CR>

map <F10> 				:set mouse=a<CR>
imap <F10>			 	<ESC>:set mouse=a<CR>
vmap <F10> 				<ESC>:set mouse=a<CR>
map <F9> 				:set mouse=c<CR>
imap <F9>			 	<ESC>:set mouse=c<CR>
vmap <F9> 				<ESC>:set mouse=c<CR>

inoremap <c-w>				<ESC>:w!<CR>
inoremap <c-q>				<ESC>:q!<CR>
inoremap <c-s>				<ESC>:w!<CR>
noremap <c-w>				<ESC>:w!<CR>
noremap <c-q>				<ESC>:q!<CR>
noremap <c-s>				<ESC>:w!<CR>

noremap <S-Right>			<C-w><Right>
noremap <S-Left>			<C-w><Left>
noremap <S-Up>				<C-w><Up>
noremap <S-Down>			<C-w><Down>

vmap <C-c>					"+y
nmap <S-q>					A*/<ESC>I/*<ESC>

nmap <F8>					<ESC>:Termdebug<CR>file 

"---------------VimPlug------------------"

call plug#begin('~/.vim/plugged')

Plug 'Shougo/vimproc', { 'do': 'make' }

Plug 'vim-syntastic/syntastic'

Plug 'tpope/vim-fugitive'

Plug 'tpope/vim-surround'

Plug 'pbondoer/vim-42header'

Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'

Plug 'frazrepo/vim-rainbow'

Plug 'SirVer/ultisnips'

Plug 'preservim/nerdtree'

Plug 'jayli/vim-easycomplete'

Plug 'tpope/vim-commentary'

call plug#end()
"---------------NerdTree---------------"

" Démarre NERDTree, sauf si un fichier ou une session est spécifié, par exemple vim -S session_file.vim.
autocmd VimEnter * if argc() == 0 && !exists('s:std_in') && v:this_session == '' | NERDTree | endif
" Fermez l'onglet si NERDTree est la seule fenêtre restante.
autocmd BufEnter * if winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif

:let g:NERDTreeWinSize=50
:let g:Tlist_WinWidth=50
 
"---------------UltiSnips--------------"

let g:UltiSnipsSnippetDirectories=["mysnips"]
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"
let g:UltiSnipsJumpBackwardTrigger="<S-tab>"
let g:UltiSnipsEditSplit="vertical"

"---------------Rainbow----------------"

let g:rainbow_active=1
let g:rainbow_load_separately=[
    \ [ '*' , [['(', ')'], ['\[', '\]'], ['{', '}']] ],
    \ [ '*.tex' , [['(', ')'], ['\[', '\]']] ],
    \ [ '*.cpp' , [['(', ')'], ['\[', '\]'], ['{', '}']] ],
    \ [ '*.{html,htm}' , [['(', ')'], ['\[', '\]'], ['{', '}'], ['<\a[^>]*>', '</[^>]*>']] ],
    \ ]

"---------------AirLine------------------"

let g:airline#extensions#tabline#formatter='unique_tail'
let g:airline_theme='murmur'
let g:airline#extensions#tabline#enabled =1
let g:airline_detect_modified=1
let g:airline_detect_past=1

"---------------Synstastic-----------------"

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let current_compiler="gcc"
let g:syntastic_cpp_compiler='gcc'
let g:syntastic_cpp_compiler_options='-std=c++11 -stdlib=libc++ -Wall-Werror -Wextra'
let g:syntastic_always_populate_loc_list=1
let g:syntastic_auto_loc_list=1
let g:syntastic_check_on_open=1
let g:syntastic_check_on_wq=1
let g:syntastic_cpp_check_header=1
let g:syntastic_cpp_remove_include_errors=1
let g:syntastic_c_remove_include_errors=1
let g:syntastic_c_include_dirs=['../../../include','../../include','../include','./include']

let g:easycomplete_tabnine_enable=0
""let g:easycomplete_tabnine_config={
    \ 'line_limit': 1000,
    \ 'max_num_result' : 10,
    \ }
"---------------EasyComplete----------------"

let g:easycomplete_tab_trigger="<c-space>"
