```
cd benchmark
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_INSTALL_PREFIX:PATH=../../local
make
make install
cd ../..
g++ $(< flags) -o bench main.cpp -lbenchmark
./bench
```

