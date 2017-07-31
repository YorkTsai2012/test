
all: bind unbind

bind: bind.o
	g++ -g -o bind bind.o -ltirpc

unbind: unbind.o
	g++ -g -o unbind unbind.o -ltirpc

bind.o: bind6_nfs_mnt.c
	g++ -g -c -o bind.o bind6_nfs_mnt.c -I/usr/include/tirpc

unbind.o: unbind6_nfs_mnt.c
	g++ -g -c -o unbind.o unbind6_nfs_mnt.c -I/usr/include/tirpc


.PHONY: clean
clean:
	rm -f bind
	rm -f unbind
	rm -f *.o
