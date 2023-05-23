cat /etc/passwd |sed 's/:/:|/g'| tr ":" "\n" | grep -v '|'| sed '1d'| sed '1~2p' | rev | sort -r |head -n $FT_LINE2 | tail -n $(($FT_LINE2-$FT_LINE1)) | tr "\n" "," | sed 's/,/, /g'|rev | sed 's/ ,/./' | rev

