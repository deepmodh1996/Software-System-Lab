    g++ --std=c++0x fibo.cpp

    for i in $(seq 1 46);
    do
      ./a.out $i >> data.csv;
    done
