Installation Instructions

    1. cd build_unix
    2. ../dist/configure
    3. 加 -lm 在 build_unix/Makefile 里的 LIBS(72行)

    4. 在 build_unix/Makefile 1641行后面加入：
	coconut_plus_heap.lo: $(exampledir)/c/coconut_plus_heap.c
		$(CC) $(CFLAGS) $?
	coconut_plus_heap: coconut_plus_heap.lo
		$(CCLINK) -o $(LDFLAGS) $@ coconut_plus_heap.lo -L./ -lmy_heap  -I . -Xlinker -rpath=./ $(DEF_LIB) $(LIBS)
		$(POSTLINK) $@

    my_heap: $(exampledir)/c/my_heap.cpp
    	g++ ../examples/c/my_heap.cpp -shared -o ./libmy_heap.so -I./ -fPIC

    5. make

    6. make my_heap

    7. make coconut_plus_heap

    参数:
    datasize(recordsnum) memsize(recordsnum) exact(0/1) 
    number_of_queries (0=only_querying/1=only_indexing/2=both_indexing_and_querying) 
    leaf_size(recordsnum) dataset_file queries_file ts_size k


    构建并且近似查询100个,k=100
    ./coconut_plus_heap 1000000 100000 0 100 2 2000 ../../ts/1.bin ../../ts/01.bin 256 100

    构建并且精确查询100,k=100
    ./coconut_plus_heap 1000000 100000 1 10 2 2000 ../../ts/1.bin ../../ts/01.bin 256 100
