while true
do
	echo testing...
	./gen > data.in
	./w <data.in >>data.in
	./ck <data.in 
done