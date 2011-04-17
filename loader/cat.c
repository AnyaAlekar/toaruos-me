#include <syscall.h>

int main(int argc, char ** argv) {
	if (argc < 2) {
		syscall_print("Expected a filename.\n");
		return -1;
	} else {
		int i = syscall_open(argv[1], 0, 0);
		if (i < 0) {
			syscall_print("cat: could not open '");
			syscall_print(argv[1]);
			syscall_print("': no such file or directory\n");
			return 1;
		}
		char dat[2] = {0, 0};
		int read = 0;
		while ((read = syscall_read(i, dat, 1))) {
			syscall_print(dat);
		}
		syscall_close(i);
	}
	return 0;
}

/*
 * vim:tabstop=4
 * vim:noexpandtab
 * vim:shiftwidth=4
 */
