# Lines configured by zsh-newuser-install
HISTFILE=~/.zsh_history
HISTSIZE=1000
SAVEHIST=1000
bindkey -e
bindkey "^[[1;5D" backward-word      # Ctrl + Left Arrow
bindkey "^[[1;5C" forward-word
bindkey "^H" backward-kill-word
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

#ls alias
alias ls="ls --color"


# Enable for git
autoload -Uz vcs_info
precmd() { vcs_info }

zstyle ':vcs_info:git:*' formats '%F{green}[%b]%f'
zstyle ':vcs_info:*' enable git

#my prompt
PROMPT="%B%F{green}%m%f%b%F{pink}%f %F{magenta}%~%f %F{red}%f ${vcs_info_msg_0_}"


#Some Alias
alias cls=clear
alias myproj="cd ~/Desktop/myproj"
