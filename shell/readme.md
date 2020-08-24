# shell

## zsh

```bash
sudo apt-get install zsh
chsh -s /bin/zsh

sudo vim /etc/passwd
```

sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"



## vim

<https://github.com/junegunn/vim-plug>


Vim-Rainbow

Plug 'junegunn/vim-easy-align'

" Any valid git URL is allowed
Plug 'https://github.com/junegunn/vim-github-dashboard.git'

" Multiple Plug commands can be written in a single line using | separators
Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'


```bash

call plug#begin('~/.vim/plugged')
Plug 'beanworks/vim-phpfmt' 
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' } 
Plug 'kien/ctrlp.vim'
Plug 'rking/ag.vim'
Plug 'jnwhiteh/vim-golang'
Plug 'tomasr/molokai'
Plug 'fatih/vim-go'
Plug 'vim-scripts/taglist.vim'
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'tpope/vim-git'
Plug 'vim-scripts/DirDiff.vim'
Plug 'vim-scripts/vimgrep.vim'
Plug 'scrooloose/syntastic'
Plug 'altercation/vim-colors-solarized'
Plug 'grep.vim'
Plug 'iamcco/markdown-preview.vim'
Plug 'tpope/vim-markdown'

call plug#end()
```
