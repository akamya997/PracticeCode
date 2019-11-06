./gen > data.in
./w < data.in > data.out
./ac < data.in >ac.out
diff ac.out data.out

