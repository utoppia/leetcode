set nocompatible
filetype on

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()


Plugin 'VundleVim/Vundle.vim'

Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'

set t_Co=256
set laststatus=2
let g:airline_theme='luna'
let g:airline_powerline_fonts=1
let g:airline#extensions#tabline#enabled=1
let g:airline#extensions#tabline#left_sep=' '
let g:airline#exetnsions#tabline#left_alt_sep='|'
let g:airline#extensions#tabline#buffer_nr_show=1

nnoremap [b :bp<CR>
nnoremap ]b :bn<CR>

map <leader>1 :b 1<CR>
map <leader>2 :b 2<CR>
map <leader>3 :b 3<CR>
map <leader>4 :b 4<CR>
map <leader>5 :b 5<CR>
map <leader>6 :b 6<CR>
map <leader>7 :b 7<CR>
map <leader>8 :b 8<CR>
map <leader>9 :b 9<CR>
set guifont=Powerline_Consolas:h14:cANSI

Plugin 'taglist.vim'
map <F3> :TlistToggle<CR>
let Tlist_Use_Right_window=1
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_WinWidth=25

Plugin 'The-NERD-tree'
map <F2> :NERDTreeToggle<CR>
let NERDTreeWinSize=25

Plugin 'indentLine.vim'
Plugin 'delimitMate.vim'

Plugin 'ycm-core/youcompleteme'

Plugin 'fatih/vim-go'

Plugin 'posva/vim-vue'

" Plugin 'SirVer/ultisnips'
" Plugin 'honza/vim-snippets'

" let g:UltiSnipsExpandTrigger = "<tab>"
" let g:UltiSnipsListSnippets = "<c-tab>"
" let g:UltiSnipsJumpForwardTrigger = "<c-f>"
" let g:UltiSnipsJumpBackwardTrigger = "<c-b>"
" let g:UltiSnipsEditSplite="vertical"
" let g:UltiSnipsSnippetDirectories=[$HOME.'.vim/UltiSnips']

call vundle#end()


"" Configuration of Function SetTitle, which
"" can insert file headers when create a new file.
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java,*.go exec ":call SetTitle()"
func SetTitle()
	if &filetype == 'sh'
		call setline(1, "######################################")
		call append(line("."), " File Name : ".expand("%"))
		call append(line("."), "")
	endif
	autocmd BufNewFile * normal G
endfunc


""""""""""""""""""""""""""""""
" Keybord commands
""""""""""""""""""""""""""""""

nmap <leader>w :w!<CR>
nmap <leader>f :find<CR>

" use Ctrl-A to select all 
map <C-A> ggVGY
map <C-A> <Esc>ggVGY
map <F12> gg=g
" user Ctrl-C to copy when selected
vmap <C-c> "+y


"""""""""""""""""""""""""""""
" Usefule configurations
"""""""""""""""""""""""""""""

set autoread " auto reload file when file modified
autocmd FileType c,cpp map <buffer> <leader><space> :w<CR>:make<CR>
set completeopt=preview,menu
filetype plugin on
set clipboard=unnamed
set nobackup
set autowrite
set ruler
set cursorline
set magic
set guioptions-=T
set guioptions-=m
set foldcolumn=0
set foldlevel=3
set nocompatible
set syntax=on
set noeb
set confirm
set autoindent
set cindent
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set smarttab
set number
set history=100
set noswapfile
set ignorecase
set hlsearch
set incsearch
set gdefault
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set statusline=%F%m%r%h%w\ [Format=%{&ff}]\ [Type=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
filetype on
filetype plugin on
filetype indent on
set viminfo+=!
set iskeyword+=_,$,@,%,#,-
set linespace=0
set wildmenu
set backspace=2
set whichwrap+=<,>,h,l
set mouse=a
set selection=exclusive
set selectmode=mouse,key
set report=0
set fillchars=vert:\ ,stl:\ ,stlnc:\ 
set showmatch
set matchtime=1
set scrolloff=3
set smartindent


colorscheme onehalfdark

au BufRead,BufNewFile * setfiletype txt

"" set tab stop for different filetypes
autocmd FileType python,javascript setlocal sta sw=2 sts=2

"" auto complete
:inoremap ( ()<Esc>i
:inoremap } <C-R>=ClosePair(')')<CR>
:inoremap [ []<Esc>i
:inoremap ] <C-R>=ClosePair(']')<CR>
:inoremap " ""<Esc>i
:inoremap ' ''<Esc>i
function! ClosePair(char)
	if getline('.')[col('.') - 1] == a:char
		return "\<Right>"
	else
		return a:char
	endif
endfunction
filetype plugin indent on
set completeopt=longest,menu

let mapleader = " "
nnoremap <leader>c gg"+yG
