all: thread_server_per_client prethread_server_per_client prethread_server_main_accept

%: %.cc
	g++ -o $@ $< -lpthread

clean:
	find . -type f -perm "u=rwx,go=rx" -exec rm {} \;
