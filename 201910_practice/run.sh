CNT=0
while true
do
	CNT=$[CNT+1]
	echo -n "testing"
	echo $CNT
	./gen > data.in
	./w < data.in > data.out
	./ac < data.in > ac.out
	diff data.out ac.out > diff.out
	if [ $? -ne 0 ]; then
		cat diff.out
		exit
	fi
done
