while true
do
	echo testing...
	./gen > data.in
	./bf <data.in >ac.out
	./w <data.in >w.out
	diff ac.out w.out > diff.out
	if [ $? -ne 0 ]; then
		cat diff.out
		exit
	fi
done