id -G -n $FT_USER | sed 's/ /,/g' | tr "\n" "|"  | sed 's/|//g'

