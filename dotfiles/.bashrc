#
# ~/.bashrc
#

export LANG=zh_CN.UTF-8
export LANGUAGE=zh_CN:en_US
export LC_CTYPE=en_US.UTF-8
export LC_ALL="zh_CN.UTF-8"

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
PS1='[\u@\h \W]\$ '

fq (){
    if [ $1 == "unable" ]
    then
        export http_proxy=
        export https_proxy=
    else
        
    export http_proxy=http://`cat ~/.lantern/settings.yaml | grep -Eo 'addr: (.*)' | sed "s/addr: //g"`
    if [ $? -ne 0 ]
    then
        echo "change http_proxy failed"
    else
        echo "changing http_proxy ......"
    fi




    export https_proxy=http://`cat ~/.lantern/settings.yaml | grep -Eo 'addr: (.*)' | sed "s/addr: //g"`
    if [ $? -ne 0 ]
    then
        echo "change https_proxy failed"
    else
        echo "changing https_proxy ......"
    fi
fi
}
