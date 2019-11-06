g++ gen.cpp -o g
./g >data.in
g++ bzoj2243.cpp -o w
./w <data.in >data.out
g++ ac.cpp -o ac
./ac <data.in >ac.out
