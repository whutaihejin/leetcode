srcs = deadlock epoll lock mmap_copy poll readv_writev record_lock select
all: $(srcs)

%: %.c
	gcc -g -O0 -std=c99 -o $@ $<

%: %.cc
	g++ -g -O0 -std=c++11 -lpthread -o $@ $<

clean:
	rm -rf $(srcs)
	rm -rf *.dSYM
