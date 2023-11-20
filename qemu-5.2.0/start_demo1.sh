#!/bin/sh

if [ $# -eq 0 ]
  then
    ram_size="1G"
  else
    ram_size=$1
fi

tmux new-session -s mysession -n debug1 -d './debug1.sh $ram_size; read -p "Press [Enter] to exit..."'
tmux new-window -t mysession:1 -n child_sock './child_sock.sh; read -p "Press [Enter] to exit..."'
tmux attach -t mysession

: <<'END_COMMENT'
Inside the tmux session, you can navigate between the two script windows using:

Ctrl-b n : Switch to the next window.
Ctrl-b p : Switch to the previous window.
Ctrl-b d : Detach from the tmux session without ending it. You can later reattach using tmux attach -t mysession.

End the session (after detaching): tmux kill-session -t mysession

END_COMMENT