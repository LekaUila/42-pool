ifconfig -a | grep ether | sed 's/        ether //g' | sed 's/  txqueuelen 1000  (Ethernet)//g'

