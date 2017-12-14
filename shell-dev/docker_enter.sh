#!/bin/bash
# This is a bit more complex than nsenter alone. OS-1505 and STORAGE-16673# We have a bash interactive login shell (to source /etc/profile and set PATH)# running a command to set the TERM and run either bash or the cmd passed.# nsenter inherited the admin user env so this is all in an effort# to minimize the changes in user experience while fixing the user namespace
if [ $# -ne 0 ]then    notallowed="^bash|^sh|^rbash|^/bin/bash|^/usr/bin/sh|^/bin/sh|^/usr/bin/rbash"    if [[ $@ =~ $notallowed ]]    then        cat<<-EOF        Usage:
            dockobj [in-line-command]
        Where:
            With no [in-line-command] you will get an interactive bash shell in object-main
            An [in-line-command] is invoked in the objec-main context and returned to host
        Notes:
            Do not pass any arguments if you simply want an interactive 'shell'
            Do not prefix an in-line command with any kind of shell invocationEOF        exit 1    fifi
if [ $# -eq 0 ]then    # provides prompt in the container    
docker exec -it object-main bash -l -c "export TERM=xterm && bash"
else    # runs the command passed in the container context    
docker exec object-main bash -l -c "export TERM=xterm && $*"fi
exit 0
