# Lines configured by zsh-newuser-install
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=1000
bindkey -e
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/my/.zshrc'

autoload -Uz compinit
compinit

# Enable command autocorrection
setopt CORRECT

#Enable command spelling correction
setopt CORRECT_ALL

# ZSH autocorrection
source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

#ZSH syntax highlighting
source ~/.zsh/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

#My prompt 
PROMPT='%F{green}%n%f%F{blue}@%f%F{pink}%m%f : %F{magenta}%~%f %F{red}>>%f '


#ls alias
alias ls="ls --color"


